
#include "RgbAnimations.h"

RgbAnimations::RgbAnimations(long now) {
  this->time = now;
  pinMode(DIGITAL_PIN,OUTPUT);
  digitalWrite(DIGITAL_PIN,0);
  if((this->rgb_arr = (uint8_t *)malloc(NUM_BYTES))) {
    memset(this->rgb_arr, 0, NUM_BYTES);
  }
  this->render();

  this->selectAnimation();
  this->ledCount = NUM_RGB;
}

void RgbAnimations::setColorRGB(uint8_t idx, uint8_t *color) {
  if(idx < NUM_RGB) {
    uint8_t *p = &rgb_arr[idx*3];
    *p++ = *color;
    *p++ = *(color + 1);
    *p = *(color + 2);
  }
}

void RgbAnimations::setColorRGBInt(uint8_t idx, uint32_t color) {
  if(idx < NUM_RGB) {
    uint8_t *p = &rgb_arr[idx*3];
    *p++ = COLOR_R(color);
    *p++ = COLOR_G(color);
    *p   = COLOR_B(color);
  }
}

uint32_t RgbAnimations::readColorRGBInt(uint8_t idx) {
  if(idx < NUM_RGB) {
    uint8_t *p = &rgb_arr[idx*3];
    return COLOR(*(p), *(p+1), *(p+2));
  }
  return 0;
}

void RgbAnimations::render() {
  if(!this->rgb_arr) return;

  while((micros() - this->t_f) < 50L);  // wait for 50us (data latch)

  cli(); // Disable interrupts so that timing is as precise as possible
  volatile uint8_t
   *p    = this->rgb_arr,   // Copy the start address of our data array
    val  = *p++,      // Get the current byte value & point to next byte
    high = PORT |  _BV(PORT_PIN), // Bitmask for sending HIGH to pin
    low  = PORT & ~_BV(PORT_PIN), // Bitmask for sending LOW to pin
    tmp  = low,       // Swap variable to adjust duty cycle
    nbits= NUM_BITS;  // Bit counter for inner loop
  volatile uint16_t
    nbytes = NUM_BYTES; // Byte counter for outer loop
  asm volatile(
  // The volatile attribute is used to tell the compiler not to optimize
  // this section.  We want every instruction to be left as is.
  //
  // Generating an 800KHz signal (1.25us period) implies that we have
  // exactly 20 instructions clocked at 16MHz (0.0625us duration) to
  // generate either a 1 or a 0---we need to do it within a single
  // period.
  //
  // By choosing 1 clock cycle as our time unit we can keep track of
  // the signal's phase (T) after each instruction is executed.
  //
  // To generate a value of 1, we need to hold the signal HIGH (maximum)
  // for 0.8us, and then LOW (minimum) for 0.45us.  Since our timing has a
  // resolution of 0.0625us we can only approximate these values. Luckily,
  // the WS281X chips were designed to accept a +/- 300ns variance in the
  // duration of the signal.  Thus, if we hold the signal HIGH for 13
  // cycles (0.8125us), and LOW for 7 cycles (0.4375us), then the variance
  // is well within the tolerated range.
  //
  // To generate a value of 0, we need to hold the signal HIGH (maximum)
  // for 0.4us, and then LOW (minimum) for 0.85us.  Thus, holding the
  // signal HIGH for 6 cycles (0.375us), and LOW for 14 cycles (0.875us)
  // will maintain the variance within the tolerated range.
  //
  // For a full description of each assembly instruction consult the AVR
  // manual here: http://www.atmel.com/images/doc0856.pdf
    // Instruction        CLK     Description                 Phase
   "nextbit:\n\t"         // -    label                       (T =  0)
    "sbi  %0, %1\n\t"     // 2    signal HIGH                 (T =  2)
    "sbrc %4, 7\n\t"      // 1-2  if MSB set                  (T =  ?)
     "mov  %6, %3\n\t"    // 0-1   tmp'll set signal high     (T =  4)
    "dec  %5\n\t"         // 1    decrease bitcount           (T =  5)
    "nop\n\t"             // 1    nop (idle 1 clock cycle)    (T =  6)
    "st   %a2, %6\n\t"    // 2    set PORT to tmp             (T =  8)
    "mov  %6, %7\n\t"     // 1    reset tmp to low (default)  (T =  9)
    "breq nextbyte\n\t"   // 1-2  if bitcount ==0 -> nextbyte (T =  ?)
    "rol  %4\n\t"         // 1    shift MSB leftwards         (T = 11)
    "rjmp .+0\n\t"        // 2    nop nop                     (T = 13)
    "cbi   %0, %1\n\t"    // 2    signal LOW                  (T = 15)
    "rjmp .+0\n\t"        // 2    nop nop                     (T = 17)
    "nop\n\t"             // 1    nop                         (T = 18)
    "rjmp nextbit\n\t"    // 2    bitcount !=0 -> nextbit     (T = 20)
   "nextbyte:\n\t"        // -    label                       -
    "ldi  %5, 8\n\t"      // 1    reset bitcount              (T = 11)
    "ld   %4, %a8+\n\t"   // 2    val = *p++                  (T = 13)
    "cbi   %0, %1\n\t"    // 2    signal LOW                  (T = 15)
    "rjmp .+0\n\t"        // 2    nop nop                     (T = 17)
    "nop\n\t"             // 1    nop                         (T = 18)
    "dec %9\n\t"          // 1    decrease bytecount          (T = 19)
    "brne nextbit\n\t"    // 2    if bytecount !=0 -> nextbit (T = 20)
    ::
    // Input operands         Operand Id (w/ constraint)
    "I" (_SFR_IO_ADDR(PORT)), // %0
    "I" (PORT_PIN),           // %1
    "e" (&PORT),              // %a2
    "r" (high),               // %3
    "r" (val),                // %4
    "r" (nbits),              // %5
    "r" (tmp),                // %6
    "r" (low),                // %7
    "e" (p),                  // %a8
    "w" (nbytes)              // %9
  );
  sei();                          // Enable interrupts
  this->t_f = micros();                 // t_f will be used to measure the 50us
                                  // latching period in the next call of the
                                  // function.
}

void RgbAnimations::selectColor() {
  int firstColor = random(0, 16);
  int secondColor = random(0, 16);
  while(firstColor == secondColor) {
    secondColor = random(0, 16);
  }
  memcpy(this->currentColor, this->colors[firstColor], 3);
  memcpy(this->backgroundColor, this->colors[secondColor], 3);
  memcpy(this->paintingColor, this->currentColor, 3);
}

void RgbAnimations::selectAnimation() {
  this->currentAnimation = random(0, 4);
  this->selectColor();
  this->currentPixel = 0;
  this->blankPixels = false;
  this->counter = 10;
  this->delay = random(50, 250);
}

bool RgbAnimations::race() {
  this->setColorRGB(this->currentPixel, this->currentColor);

  this->currentPixel++;
  if(this->currentPixel == this->ledCount) {
    this->currentPixel = 0;
    this->blankPixels = !this->blankPixels;
    memcpy(this->currentColor, this->blankPixels ? this->black : this->paintingColor, 3);
    if(this->blankPixels) {
      this->counter--;
    }
  }
  return this->counter == 0;
}

bool RgbAnimations::circleColor() {
  for(unsigned int ii=0;ii < this->ledCount;ii++) {
    this->setColorRGB(ii, this->backgroundColor);
  }
  this->setColorRGB(this->currentPixel, this->currentColor);

  this->currentPixel++;
  if(this->currentPixel == this->ledCount) {
    this->currentPixel = 0;
    this->counter--;
  }
  return this->counter == 0;
}

bool RgbAnimations::circle() {
  for(unsigned int ii=0;ii < this->ledCount;ii++) {
    this->setColorRGB(ii, this->black);
  }
  this->setColorRGB(this->currentPixel, this->currentColor);

  this->currentPixel++;
  if(this->currentPixel == this->ledCount) {
    this->currentPixel = 0;
    this->counter--;
  }
  return this->counter == 0;
}

#define BOUNCE_SIZE 9
unsigned int bounceIndex[BOUNCE_SIZE] = {
  7, 0, 1, 2, 3, 4, 5, 6, 7
};

bool RgbAnimations::bounceCircle() {
  for(unsigned int ii=0;ii < this->ledCount;ii++) {
    this->setColorRGB(ii, this->black);
  }
  this->setColorRGB(bounceIndex[this->currentPixel], this->currentColor);

  if(this->blankPixels) {
    this->currentPixel--;
  } else {
    this->currentPixel++;
  }
  if((this->currentPixel == BOUNCE_SIZE && !this->blankPixels) || (this->currentPixel == 0 && this->blankPixels)) {
    this->currentPixel = 0;
    this->blankPixels = !this->blankPixels;
    this->counter--;
    if(this->blankPixels) {
      this->currentPixel = BOUNCE_SIZE - 1;
    }
  }
  return this->counter == 0;
}

bool RgbAnimations::theaterChase() {

}

bool RgbAnimations::theaterChaseRainbow() {

}

uint32_t RgbAnimations::wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return COLOR(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return COLOR(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return COLOR(WheelPos * 3, 255 - WheelPos * 3, 0);
}

void RgbAnimations::run(long now) {
  if(now - this->time >= this->delay) {
    this->time = now;
    bool result = false;
    switch(this->currentAnimation) {
      case 0:
        result = this->race();
        break;
      case 1:
        result = this->circle();
        break;
      case 2:
        result = this->bounceCircle();
        break;
      case 3:
        result = this->circleColor();
        break;
      case 4:
      case 5:
      case 6:
      case 7:
      case 8:
      case 9:
      case 10:
      case 11:
      case 12:
      case 13:
      case 14:
      case 15:
      break;
    }
    this->render();
    if(result) {
      this->selectAnimation();
    }
  }
}

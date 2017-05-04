
#include "RgbAnimations.h"

RgbAnimations::RgbAnimations(Adafruit_NeoPixel *leds, unsigned int ledCount) {
  this->leds = leds;
  this->selectAnimation();
  this->ledCount = ledCount;

  this->colors[0] = this->leds->Color(8, 0, 0);
  this->colors[1] = this->leds->Color(0, 8, 0);
  this->colors[2] = this->leds->Color(0, 0, 8);
  this->colors[3] = this->leds->Color(8, 8, 0);
  this->colors[4] = this->leds->Color(8, 0, 8);
  this->colors[5] = this->leds->Color(0, 8, 8);
  this->colors[6] = this->leds->Color(8, 0, 3);
  this->colors[7] = this->leds->Color(8, 3, 0);
  this->colors[8] = this->leds->Color(3, 8, 0);
  this->colors[9] = this->leds->Color(0, 8, 3);
  this->colors[10] = this->leds->Color(3, 0, 8);
  this->colors[11] = this->leds->Color(0, 3, 8);
  this->colors[12] = this->leds->Color(8, 8, 3);
  this->colors[13] = this->leds->Color(8, 3, 8);
  this->colors[14] = this->leds->Color(3, 8, 8);
  this->colors[15] = this->leds->Color(8, 8, 8);
}
unsigned int RgbAnimations::selectColor() {
  return this->colors[random(0, 16)];
}

void RgbAnimations::selectAnimation() {
  this->currentAnimation = random(0, 16);
  this->paintingColor = this->selectColor();
  this->currentPixel = 0;
  this->currentColor = this->paintingColor;
  this->blankPixels = false;
  this->counter = 10;
}

bool RgbAnimations::race() {
  this->leds->setPixelColor(this->currentPixel, this->currentColor);

  this->currentPixel++;
  if(this->currentPixel == this->ledCount) {
    this->currentPixel = 0;
    this->blankPixels = !this->blankPixels;
    this->currentColor = this->blankPixels ? this->leds->Color(0, 0, 0) : this->paintingColor;
    if(this->blankPixels) {
      this->counter--;
    }
  }
  return this->counter == 0;
}

bool RgbAnimations::circle() {
  for(unsigned int ii=0;ii < this->ledCount;ii++) {
    this->leds->setPixelColor(ii, this->leds->Color(0, 0, 0));
  }
  this->leds->setPixelColor(this->currentPixel, this->currentColor);

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
    this->leds->setPixelColor(ii, this->leds->Color(0, 0, 0));
  }
  this->leds->setPixelColor(bounceIndex[this->currentPixel], this->currentColor);

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

bool RgbAnimations::run() {
  bool result;
  switch(this->currentAnimation) {
    case 0:
    case 1:
    case 2:
    case 3:
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
    default:
      result = this->circle();
      break;
  }
  this->leds->show();
  if(result) {
    this->selectAnimation();
  }
  return result;
}

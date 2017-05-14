#define NEED_CXX_BITS

#include "RgbAnimations.h"
#include "Lcd.h"

#define LCD_DELAY 250
Lcd *lcd;

RgbAnimations *animations;
unsigned int rgbDelay = 50;

long rgbTime;
long lcdTime;

void setup() {
  randomSeed(0xCAFEF00D);

  animations = new RgbAnimations();
  lcd = new Lcd();
  lcdTime = rgbTime = millis();
}

void loop() {
  long now = millis();
  if(now - rgbTime >= rgbDelay) {
    rgbTime = now;
    if(animations->run()) {
      rgbDelay = random(50, 250);
    }
  }
  if(now - lcdTime >= LCD_DELAY) {
    lcdTime = now;
    lcd->run();
  }
}

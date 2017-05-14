#define NEED_CXX_BITS

#include "RgbAnimations.h"
#include "Lcd.h"

Lcd *lcd;

RgbAnimations *animations;
unsigned int rgbDelay = 50;

long rgbTime;
long lcdTime;

void setup() {
  randomSeed(0xCAFEF00D);

  long now = millis();

  animations = new RgbAnimations(now);
  lcd = new Lcd(now);
}

void loop() {
  long now = millis();
  animations->run(now);
  lcd->run(now);
}

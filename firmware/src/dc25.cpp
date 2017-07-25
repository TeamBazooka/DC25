#define NEED_CXX_BITS

#include "RgbAnimations.h"
#include "Lcd.h"

Lcd *lcd;
RgbAnimations *animations;

long now;

void setup() {
  randomSeed(0xDEADBEEF);

  now = millis();

  animations = new RgbAnimations(now);
  lcd = new Lcd(now);
}

void loop() {
  now = millis();
  animations->run(now);
  lcd->run(now);
}

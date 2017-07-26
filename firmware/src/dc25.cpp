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

#define SLEEP_COUNT 300
bool masterSleep = false;
bool wake = false;

void loop() {
  if(masterSleep) {
    for(unsigned int ii = 0; ii < SLEEP_COUNT; ii++) {
      delay(1000);
    }
    masterSleep = !masterSleep;
    wake = true;
    goto END;
  } else {
    now = millis();
    bool sleepLcd = lcd->run(now, wake);
    bool sleepRgb = animations->run(now, sleepLcd, wake);
    masterSleep = sleepLcd && sleepRgb;
  }
  wake = false;
END:
  return;
}

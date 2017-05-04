
#ifndef __RGB_ANI_H
#define __RGB_ANI_H

#include <Adafruit_NeoPixel.h>

class RgbAnimations {
  private:
  Adafruit_NeoPixel *leds;
  unsigned int currentAnimation;
  unsigned int currentPixel;
  unsigned int ledCount;
  unsigned int colors[16];
  unsigned int currentColor;
  unsigned int paintingColor;
  bool blankPixels;
  unsigned int counter;

  unsigned int selectColor();
  bool race();
  bool circle();
  bool bounceCircle();
  public:
  RgbAnimations(Adafruit_NeoPixel *leds, unsigned int ledCount);
  void selectAnimation();
  bool run();
};

#endif

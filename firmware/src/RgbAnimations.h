
#ifndef __RGB_ANI_H
#define __RGB_ANI_H

#include <stdint.h>
#include <Arduino.h>

#define NUM_RGB       (8)         // Number of WS281X we have connected
#define NUM_BYTES     (NUM_RGB*3) // Number of LEDs (3 per each WS281X)
#define DIGITAL_PIN   (PD2)         // Digital port number
#define PORT          (PORTD)     // Digital pin's port
#define PORT_PIN      (PORTD2)    // Digital pin's bit position
#define NUM_BITS      (8)         // Constant value: bits per byte

#define COLOR(r, g, b) (((uint32_t)(r) << 16) | ((uint32_t)(g) <<  8) | (b))
#define COLOR_R(r)     ((uint8_t)(0xff0000 & (r)) >> 16)
#define COLOR_G(g)     ((uint8_t)(0x00ff00 & (g)) >> 8)
#define COLOR_B(b)     ((uint8_t)(0x0000ff & (b)))

class RgbAnimations {
  private:
  long time;
  uint8_t delay;
  unsigned int currentAnimation;
  unsigned int currentPixel;
  unsigned int ledCount;
  uint8_t colors[16][3] = {
    {8, 0, 0},
    {0, 8, 0},
    {0, 0, 8},
    {8, 8, 0},
    {8, 0, 8},
    {0, 8, 8},
    {8, 0, 3},
    {8, 3, 0},
    {3, 8, 0},
    {0, 8, 3},
    {3, 0, 8},
    {0, 3, 8},
    {8, 8, 3},
    {8, 3, 8},
    {3, 8, 8},
    {8, 8, 8}
  };
  uint8_t black[3] = { 0, 0, 0 };
  uint8_t currentColor[3];
  uint8_t paintingColor[3];
  uint8_t backgroundColor[3];
  bool blankPixels;
  unsigned int counter;


  uint8_t* rgb_arr;
  uint32_t t_f;
  void setColorRGB(uint8_t idx, uint8_t *color);
  void setColorRGBInt(uint8_t idx, uint32_t color);
  uint32_t readColorRGBInt(uint8_t idx);
  void render();

  void selectColor();
  uint32_t wheel(byte WheelPos);
  bool race();
  bool circle();
  bool circleColor();
  bool bounceCircle();
  bool theaterChase();
  bool theaterChaseRainbow();
  bool randomFlash();
  bool randomFlashColor();
  bool randomFlashMultiple();
  public:
  RgbAnimations(long now);
  void selectAnimation();
  void run(long now);
};

#endif

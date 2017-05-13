#define NEED_CXX_BITS
#include <LiquidCrystal.h>
#include <Arduino_FreeRTOS.h>

#include "strings.h"
#include "line_info.h"
#include "RgbAnimations.h"

#define SIZECHAR 1

#define COLUMNS 16
#define ROWS 2
#define LCD_DELAY 250

#define RANDOM random(0, STR_COUNT)
#define RANDOM_STOP random(4, 9)

#define RGB_LED_PIN PD2
#define RGB_LED_COUNT 8

LiquidCrystal *lcd;

LineInfo *lineOne;
LineInfo *lineTwo;

RgbAnimations *animations;
unsigned int rgbDelay = 50;

void run_lcd(void *pvParameters);
void run_rgb(void *pvParameters);

void setup() {
  randomSeed(0xCAFEF00D);
  //                       RS,  RW,   E,  D0,  D1,  D2, D3, D4, D5, D6, D7
  lcd = new LiquidCrystal(PC2, PC1, PC0, PB2, PB1, PB0, PD7, PD6, PD5, PD4, PD3);
  //lcd = new LiquidCrystal(2,  3, 4,  5,  6,  7,  8,  9, 10, 11, 12);
  // set up the LCD's number of columns and rows:
  lcd->begin(COLUMNS, ROWS);

  lineOne = liInit(COLUMNS, SIZECHAR, RANDOM);
  lineTwo = liInit(COLUMNS, SIZECHAR, RANDOM);
  while(lineOne->str == lineTwo->str) {
    lineTwo->str = RANDOM;
  }
  lineTwo->stop = RANDOM_STOP;

  animations = new RgbAnimations();
  animations->selectAnimation(false);

  // xTaskCreate(
  //     run_lcd
  //     ,  (const portCHAR *)"LCD"   // A name just for humans
  //     ,  128  // Stack size
  //     ,  NULL
  //     ,  2  // priority
  //     ,  NULL );
  //
  xTaskCreate(
      run_rgb
      ,  (const portCHAR *)"RGB"   // A name just for humans
      ,  128  // Stack size
      ,  NULL
      ,  1  // priority
      ,  NULL );
}

void incrementLine(LineInfo *currentLine, LineInfo *prevLine) {
  char thisChar;
  if(currentLine->stop != 0) {
    currentLine->stop--;
    cbPush(currentLine->cb);
  } else {
    memcpy_P(&thisChar, strings[currentLine->str] + (currentLine->ch * SIZECHAR), SIZECHAR);
    if(thisChar != '\0') {
      cbPush(currentLine->cb, &thisChar);
      currentLine->ch++;
    } else {
      currentLine->str = RANDOM;
      while(currentLine->str == prevLine->str) {
        currentLine->str = RANDOM;
      }
      currentLine->stop = RANDOM_STOP;
      currentLine->ch = 0;
      cbPush(currentLine->cb);
    }
  }
}

void writeToLcd() {
  incrementLine(lineOne, lineTwo);
  incrementLine(lineTwo, lineOne);

  char *currentColOne = lineOne->cb->head;
  char *currentColTwo = lineTwo->cb->head;
  for(int ii = 0; ii<COLUMNS;ii++) {
    lcd->setCursor(ii, 0);
    lcd->write(*currentColOne);
    lcd->setCursor(ii, 1);
    lcd->write(*currentColTwo);
    currentColOne = (char*) currentColOne + lineOne->cb->sz;
    currentColTwo = (char*) currentColTwo + lineTwo->cb->sz;
    if(currentColOne == lineOne->cb->bufferEnd) {
      currentColOne = lineOne->cb->buffer;
    }
    if(currentColTwo == lineTwo->cb->bufferEnd) {
      currentColTwo = lineTwo->cb->buffer;
    }
  }
}

void run_lcd(void *pvParameters) {
  while(1) {
    writeToLcd();
    vTaskDelay( LCD_DELAY / portTICK_PERIOD_MS );
  }
}

void run_rgb(void *pvParameters) {
  while(1) {
    bool select = animations->run(false);
    if(select) {
      rgbDelay = random(50, 250);
    }
    vTaskDelay( rgbDelay / portTICK_PERIOD_MS );
  }
}

void loop() { ; }

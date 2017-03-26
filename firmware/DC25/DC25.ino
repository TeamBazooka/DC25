#include <LiquidCrystal.h>
#include <Adafruit_NeoPixel.h>

#include "strings.h"
#include "line_info.h"

#define SIZECHAR 1

#define COLUMNS 16
#define DELAY 150

#define RANDOM random(0, STR_COUNT)
#define RANDOM_STOP random(4, 9)

LiquidCrystal lcd(2,   3, 4,  5,  6,  7,  8,  9, 10, 11, 12);

const char space = ' ';

LineInfo *lineOne;
LineInfo *lineTwo;

void setup() {
  randomSeed(0xCAFEF00D);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  lineOne = liInit();
  lineTwo = liInit();

  lineOne->cb = cbInit(COLUMNS, SIZECHAR);
  lineTwo->cb = cbInit(COLUMNS, SIZECHAR);

  for(int ii=0;ii<16;ii++) {
    cbPush(lineOne->cb, &space);
    cbPush(lineTwo->cb, &space);
  }
  lineOne->str = RANDOM;
  lineTwo->str = RANDOM;
  while(lineOne->str == lineTwo->str) {
    lineTwo->str = RANDOM;
  }
  lineTwo->stop = RANDOM_STOP;
}

void incrementLine(LineInfo *currentLine, LineInfo *prevLine) {
  char thisChar;
  if(currentLine->stop != 0) {
    currentLine->stop--;
    cbPush(currentLine->cb, &space);
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
      cbPush(currentLine->cb, &space);
    }
  }
}

void loop() {
   incrementLine(lineOne, lineTwo);
   incrementLine(lineTwo, lineOne);

  char *currentColOne = lineOne->cb->head;
  char *currentColTwo = lineTwo->cb->head;
  for(int ii = 0; ii<COLUMNS;ii++) {
    lcd.setCursor(ii, 0);
    lcd.write(*currentColOne);
    lcd.setCursor(ii, 1);
    lcd.write(*currentColTwo);
    currentColOne = (char*) currentColOne + lineOne->cb->sz;
    currentColTwo = (char*) currentColTwo + lineTwo->cb->sz;
    if(currentColOne == lineOne->cb->bufferEnd) {
      currentColOne = lineOne->cb->buffer;
    }
    if(currentColTwo == lineTwo->cb->bufferEnd) {
      currentColTwo = lineTwo->cb->buffer;
    }
  }
   delay(DELAY);
}

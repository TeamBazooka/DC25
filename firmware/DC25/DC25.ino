#include <LiquidCrystal.h>
#include <Adafruit_NeoPixel.h>

#include "buffer.h"
#include "strings.h"

#define COLUMNS 16
#define DELAY 150

#define CUR_CHAR_1 (char*)pgm_read_word(&(strings[lineOneCurrentString])) + ((lineOneCurrentChar - 1) + sizeof(char))
#define CUR_CHAR_2 (char*)pgm_read_word(&(strings[lineTwoCurrentString])) + ((lineTwoCurrentChar - 1) + sizeof(char))
//NOTE update this max when more strings are added
#define RANDOM random(0, 54)
#define RANDOM_STOP random(4, 9)

LiquidCrystal lcd(2,   3, 4,  5,  6,  7,  8,  9, 10, 11, 12);

const char space = ' ';

int lineOneCurrentString = 0;
int lineOneCurrentChar = 0;
int lineTwoCurrentString = 0;
int lineTwoCurrentChar = 0;
int lineOneStop = 0;
int lineTwoStop = 0;

circular_buffer *LineOne;
circular_buffer *LineTwo;

void setup() {
  randomSeed(analogRead(0));
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  size_t charSize = sizeof(char);
  LineOne = cb_init(COLUMNS, charSize);
  LineTwo = cb_init(COLUMNS, charSize);

  for(int ii=0;ii<16;ii++) {
    cb_push(LineOne, &space);
    cb_push(LineTwo, &space);
  }
  lineOneCurrentString = RANDOM;
  lineTwoCurrentString = RANDOM;
  while(lineOneCurrentString == lineTwoCurrentString) {
    lineTwoCurrentString = RANDOM;
  }
  lineTwoStop = RANDOM_STOP;
  Serial.begin(9600);
}

void loop() {
  char thisChar;
  char *ptrThisChar;

  if(lineOneStop != 0) {
    lineOneStop--;
    cb_push(LineOne, &space);
  } else {
    ptrThisChar = CUR_CHAR_1;
    memcpy_P(&thisChar, ptrThisChar, sizeof(char));
    if(thisChar != '\0') {
      cb_push(LineOne, &thisChar);
      lineOneCurrentChar++;
    } else {
      lineOneCurrentString = RANDOM;
      while(lineOneCurrentString == lineTwoCurrentString) {
        lineOneCurrentString = RANDOM;
      }
      lineOneStop = RANDOM_STOP;
      lineOneCurrentChar=0;
      cb_push(LineOne, &space);
    }
  }

  if(lineTwoStop != 0) {
    lineTwoStop--;
    cb_push(LineTwo, &space);
  } else {
    ptrThisChar = CUR_CHAR_2;
    memcpy_P(&thisChar, ptrThisChar, sizeof(char));
    if(thisChar != '\0') {
      cb_push(LineTwo, &thisChar);
      lineTwoCurrentChar++;
    } else {
      lineTwoCurrentString = RANDOM;
      while(lineOneCurrentString == lineTwoCurrentString) {
        lineTwoCurrentString = RANDOM;
      }
      lineTwoStop = RANDOM_STOP;
      lineTwoCurrentChar=0;
      cb_push(LineTwo, &space);
    }
  }

  char *currentColOne = LineOne->head;
  char *currentColTwo = LineTwo->head;
  for(int ii = 0; ii<COLUMNS;ii++) {
    lcd.setCursor(ii, 0);
    lcd.write(*currentColOne);
    lcd.setCursor(ii, 1);
    lcd.write(*currentColTwo);
    currentColOne = (char*) currentColOne + LineOne->sz;
    currentColTwo = (char*) currentColTwo + LineTwo->sz;
    if(currentColOne == LineOne->buffer_end) {
      currentColOne = LineOne->buffer;
    }
    if(currentColTwo == LineTwo->buffer_end) {
      currentColTwo = LineTwo->buffer;
    }
  }
  delay(DELAY);
}


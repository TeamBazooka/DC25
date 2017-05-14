
#include "Lcd.h"

Lcd::Lcd() {
  this->lcd = new LiquidCrystal(16, 15, 14, 10, 9, 8, 7, 6, 5, 4, 3);
  // set up the LCD's number of columns and rows:
  this->lcd->begin(COLUMNS, ROWS);

  this->lineOne = liInit(COLUMNS, SIZECHAR, RANDOM);
  this->lineTwo = liInit(COLUMNS, SIZECHAR, RANDOM);
  while(this->lineOne->str == this->lineTwo->str) {
    this->lineTwo->str = RANDOM;
  }
  this->lineTwo->stop = 25;
  this->lineOne->stop = 20;
}

void Lcd::incrementLine(LineInfo *currentLine, LineInfo *prevLine) {
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

void Lcd::run() {
  this->incrementLine(this->lineOne, this->lineTwo);
  this->incrementLine(this->lineTwo, this->lineOne);

  char *currentColOne = this->lineOne->cb->head;
  char *currentColTwo = this->lineTwo->cb->head;
  for(int ii = 0; ii<COLUMNS;ii++) {
    this->lcd->setCursor(ii, 0);
    this->lcd->write(*currentColOne);
    this->lcd->setCursor(ii, 1);
    this->lcd->write(*currentColTwo);
    currentColOne = (char*) currentColOne + this->lineOne->cb->sz;
    currentColTwo = (char*) currentColTwo + this->lineTwo->cb->sz;
    if(currentColOne == this->lineOne->cb->bufferEnd) {
      currentColOne = this->lineOne->cb->buffer;
    }
    if(currentColTwo == this->lineTwo->cb->bufferEnd) {
      currentColTwo = this->lineTwo->cb->buffer;
    }
  }
}

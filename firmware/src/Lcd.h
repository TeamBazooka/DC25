
#ifndef __LCD_H
#define __LCD_H

#include <LiquidCrystal.h>

#include "strings.h"
#include "line_info.h"

#define SIZECHAR 1

#define COLUMNS 16
#define ROWS 2

#define RANDOM random(0, STR_COUNT)
#define RANDOM_STOP random(4, 9)

class Lcd {
public:
  Lcd();
  void run();


private:
  void incrementLine(LineInfo *currentLine, LineInfo *prevLine);
  LineInfo *lineOne;
  LineInfo *lineTwo;
  LiquidCrystal *lcd;
};

#endif

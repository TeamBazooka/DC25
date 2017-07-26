
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

#define LCD_DELAY 250

class Lcd {
public:
  Lcd(long now);
  bool run(long now, bool wake);


private:
  long time;
  void incrementLine(LineInfo *currentLine, LineInfo *prevLine);
  LineInfo *lineOne;
  LineInfo *lineTwo;
  LiquidCrystal *lcd;
  unsigned int runcount;
};

#endif

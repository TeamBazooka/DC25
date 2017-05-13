
#ifndef __LINEINFO_H
#define __LINEINFO_H

#include "buffer.h"

typedef struct LineInfo {
  int str;
  int ch;
  int stop;
  CircularBuffer *cb;
} LineInfo;

LineInfo *liInit(unsigned int columns, unsigned int sz, int initStr);

#endif

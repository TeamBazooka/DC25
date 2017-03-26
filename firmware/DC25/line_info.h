
#ifndef __LINEINFO_H
#define __LINEINFO_H

#include "buffer.h"

typedef struct LineInfo {
  int str;
  int ch;
  int stop;
  CircularBuffer *cb;
} LineInfo;

LineInfo *liInit(size_t columns, size_t sz, int initStr) {
  LineInfo *li = (LineInfo *) malloc(sizeof(LineInfo));
  li->cb = cbInit(columns, sz);
  li->str = initStr;
  return li;
}

#endif

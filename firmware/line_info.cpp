
#include "buffer.h"
#include "line_info.h"

LineInfo *liInit(unsigned int columns, unsigned int sz, int initStr) {
  LineInfo *li = (LineInfo *) ::operator new (sizeof(LineInfo));
  li->cb = cbInit(columns, sz);
  li->str = initStr;
  return li;
}

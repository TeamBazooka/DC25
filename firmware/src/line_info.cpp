
#include "buffer.h"
#include "line_info.h"

LineInfo *liInit(unsigned int columns, unsigned int sz, int initStr) {
  LineInfo *li = (LineInfo *) ::operator new (sizeof(LineInfo));
  li->cb = cbInit(columns, sz);
  li->str = initStr;
  li->capacity = columns;
  return li;
}

bool lineEmpty(LineInfo *line) {
  bool returnVal = true;
  for(int ii=0; ii < line->capacity; ii++) {
    returnVal = returnVal && (*(line->cb->buffer + (ii * line->cb->sz)) == ' ');
  }
  return returnVal;
}

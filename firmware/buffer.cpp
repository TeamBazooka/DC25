
#include <string.h>

#include "buffer.h"

const char space = ' ';

void cbPush(CircularBuffer *cb, const char *item) {
  memcpy(cb->head, item, cb->sz);
  cb->head = cb->head + cb->sz;
  if(cb->head == cb->bufferEnd)
    cb->head = cb->buffer;
}

void cbPush(CircularBuffer *cb) {
  cbPush(cb, &space);
}

CircularBuffer* cbInit(unsigned int capacity, unsigned int sz) {
  unsigned int buffer_size = capacity * sz;
  CircularBuffer *cb = (CircularBuffer*) ::operator new (sizeof(CircularBuffer));
  cb->buffer = (char*) ::operator new (buffer_size);
  cb->bufferEnd = cb->buffer + buffer_size;
  cb->sz = sz;
  cb->head = cb->buffer;
  for(unsigned int ii=0;ii<capacity;ii++)
    cbPush(cb);
  return cb;
}


#ifndef __BUFFER_H
#define __BUFFER_H

typedef struct CircularBuffer {
    char *buffer;     // data buffer
    char *bufferEnd; // end of data buffer
    size_t sz;        // size of each item in the buffer
    char *head;       // pointer to head
} CircularBuffer;

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

CircularBuffer* cbInit(size_t capacity, size_t sz) {
  size_t buffer_size = capacity * sz;
  CircularBuffer *cb = (CircularBuffer*) malloc(sizeof(CircularBuffer));
  cb->buffer = (char*) malloc(buffer_size);
  cb->bufferEnd = cb->buffer + buffer_size;
  cb->sz = sz;
  cb->head = cb->buffer;
  for(size_t ii=0;ii<capacity;ii++)
    cbPush(cb);
  return cb;
}

#endif

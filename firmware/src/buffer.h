
#ifndef __BUFFER_H
#define __BUFFER_H

typedef struct CircularBuffer {
    char *buffer;     // data buffer
    char *bufferEnd; // end of data buffer
    unsigned int sz;        // size of each item in the buffer
    char *head;       // pointer to head
} CircularBuffer;

void cbPush(CircularBuffer *cb, const char *item);
void cbPush(CircularBuffer *cb);
CircularBuffer* cbInit(unsigned int capacity, unsigned int sz);

#endif

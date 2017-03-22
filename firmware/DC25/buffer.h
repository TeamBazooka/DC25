typedef struct circular_buffer {
    char *buffer;     // data buffer
    char *buffer_end; // end of data buffer
    size_t sz;        // size of each item in the buffer
    char *head;       // pointer to head
} circular_buffer;

circular_buffer* cb_init(size_t capacity, size_t sz) {
  size_t buffer_size = (capacity + 1) * sz;
  circular_buffer *cb = (circular_buffer*) malloc(sizeof(circular_buffer));
  cb->buffer = (char*) malloc(buffer_size);
  cb->buffer_end = cb->buffer + buffer_size;
  cb->sz = sz;
  cb->head = cb->buffer;
  return cb;
}

void cb_push(circular_buffer *cb, const char *item) {
  memcpy(cb->head, item, cb->sz);
  cb->head = cb->head + cb->sz;
  if(cb->head == cb->buffer_end)
    cb->head = cb->buffer;
}


#include "Stream.h"
#include <assert.h>
#include <string.h>

void ReadStream(Stream *stream, void *out, size_t len){
	assert(stream);
	assert(out);
	assert(len + (stream->cur-stream->base) < stream->size);
  memcpy(out, stream->cur, len);
  stream->cur += len;
}

void AdvanceStream(Stream* stream, size_t n){
	assert(stream);
	assert(n + (stream->cur-stream->base) < stream->size);
  stream->cur += n;
}

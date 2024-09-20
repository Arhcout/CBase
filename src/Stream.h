#pragma once
#include <stddef.h>
#include <stdint.h>

typedef struct Stream_s{
  uint8_t* base;
  uint8_t* cur;
	size_t size;
}Stream;

void ReadStream(Stream* stream, void* out, size_t len);
void AdvanceStream(Stream* stream, size_t n);


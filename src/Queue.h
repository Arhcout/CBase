#pragma once
#include <stddef.h>

typedef struct Queue_s{
  void* back;
  void* front;
  size_t objSize;
  size_t size;
  size_t capacity;
}Queue;

void EnQueue(Queue* queue, void* data);
//Give you the ownership (you need to free the return value)
void* DeQueue(Queue* queue);
Queue* CreateQueue(size_t typeSize, size_t baseCapacity);
void DestroyQueue(Queue* queue);

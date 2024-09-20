#include "Queue.h"
#include "Error.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

Queue *CreateQueue(size_t typeSize, size_t baseCapacity) {
  Queue *queue = malloc(sizeof(Queue));
  MALLOC_CHECK(queue, NULL);
  queue->objSize = typeSize;
  queue->size = 0;
  queue->capacity = (baseCapacity == 0) ? 1 : baseCapacity;
  queue->front = queue->back = malloc(baseCapacity * typeSize);
  if (!queue->back) {
    free(queue);
    return NULL;
  }
  return queue;
}

void DestroyQueue(Queue *queue) {
  assert(queue);
  free(queue->back);
  free(queue);
}

void EnQueue(Queue *queue, void *data) {
  assert(queue);
  assert(data);
  queue->size++;
  if (queue->capacity < queue->size) {
    queue->capacity *= 2;
    queue->back = realloc(queue->back, queue->capacity * queue->objSize);
    queue->front = queue->back + (queue->size - 1) * queue->objSize;
  }
  memcpy(queue->front, data, queue->objSize);
  queue->front += queue->objSize;
}

void *DeQueue(Queue *queue) {
  assert(queue);
  if (queue->size == 0)
    return NULL;

  void *obj = malloc(queue->objSize);
  MALLOC_CHECK(obj, NULL);
  memcpy(obj, queue->back, queue->objSize);

  queue->size--;
  queue->front -= queue->objSize;
  memcpy(queue->back, queue->back + queue->objSize,
         queue->size * queue->objSize);
  return obj;
}

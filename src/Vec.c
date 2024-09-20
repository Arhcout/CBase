#include "Vec.h"
#include <math.h>

void AddVecf2(Vecf2 *a, Vecf2 *b) {
  a->x += b->x;
  a->y += b->y;
}

void SubVecf2(Vecf2 *a, Vecf2 *b) {
  a->x -= b->x;
  a->y -= b->y;
}

float DistanceVecf2(Vecf2 *a, Vecf2 *b) {
  return sqrtf((b->x - a->x) * (b->x - a->x) + (b->y - a->y) * (b->y - a->y));
}

float DistanceSquaredVecf2(Vecf2 *a, Vecf2 *b) {
  return fabsf((b->x - a->x) * (b->x - a->x) + (b->y - a->y) * (b->y - a->y));
}

void RotateAroundPoint(Vecf2 *point, Vecf2 *center, float angle) {
  float s = sinf(angle);
  float c = cosf(angle);

  point->x -= center->x;
  point->y -= center->y;

  float rx = point->x * c - point->y * s;
  float ry = point->x * s + point->y * c;

  point->x = rx + center->x;
  point->y = ry + center->y;
}

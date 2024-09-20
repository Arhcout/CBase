#pragma once

#define VECF2_ZERO ((Vecf2){0})

typedef struct Vecf2_s {
  float x, y;
} Vecf2;

void AddVecf2(Vecf2 *a, Vecf2 *b);
void SubVecf2(Vecf2 *a, Vecf2 *b);
float DistanceVecf2(Vecf2 *a, Vecf2 *b);
float DistanceSquaredVecf2(Vecf2 *a, Vecf2 *b);
void RotateAroundPoint(Vecf2 *point, Vecf2 *center, float angle);

#define VECI2_ZERO ((Veci2){0})

typedef struct Veci2_s {
  int x, y;
} Veci2;

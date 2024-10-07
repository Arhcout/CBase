#include "Error.h"
#include <stdio.h>
#include <time.h>

void PrintTimeStamp() {
  time_t t = time(NULL);
  fprintf(stderr, "%02ld:%02ld:%02ld", (t / 3600) % 24, (t / 60) % 60, t % 60);
}

static int _errlv = LOG_LV;

void SetError(int errlv) { _errlv = errlv; }
int GetError() { return _errlv; }

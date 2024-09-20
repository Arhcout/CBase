#include "Error.h"
#include <stdio.h>
#include <time.h>

void PrintTimeStamp(){
  time_t t = time(NULL);
  fprintf(stderr, "%02ld:%02ld:%02ld",
      (t / 3600) % 24, (t / 60) % 60, t % 60);
}

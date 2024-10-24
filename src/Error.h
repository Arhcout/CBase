#pragma once
#include <assert.h>
#include <stdio.h>

#define LOG(...)                                                               \
  {                                                                            \
    fprintf(stderr, "[LOG] ");                                                 \
    PrintTimeStamp();                                                          \
    fprintf(stderr, " %s:%s:%d: ", __FILE__, __func__, __LINE__);              \
    fprintf(stderr, __VA_ARGS__);                                              \
  }

#define WARNING(...)                                                           \
  {                                                                            \
    fprintf(stderr, "\033[33m[WARNING] ");                                     \
    PrintTimeStamp();                                                          \
    fprintf(stderr, " %s:%s:%d: ", __FILE__, __func__, __LINE__);              \
    fprintf(stderr, __VA_ARGS__);                                              \
    fprintf(stderr, "\033[0m");                                                \
  }

#define ERROR(...)                                                             \
  {                                                                            \
    fprintf(stderr, "\033[31m[ERROR] ");                                       \
    PrintTimeStamp();                                                          \
    fprintf(stderr, " %s:%s:%d: ", __FILE__, __func__, __LINE__);              \
    fprintf(stderr, __VA_ARGS__);                                              \
    fprintf(stderr, "\033[0m");                                                \
  }

#define MALLOC_CHECK(val, failReturnValue)                                     \
  if (!(val)) {                                                                \
    ERROR("Out memory (malloc)\n");                                            \
    return (failReturnValue);                                                  \
  }

#define ASSERT(condition, errmsg, ...)                                         \
  if (!(condition)) {                                                          \
    ERROR(errmsg, ##__VA_ARGS__);                                              \
    assert((condition));                                                       \
  }

#define ERROR_LV 2
#define WARNING_LV 1
#define LOG_LV 0

void SetError(int errlv);
int GetError();

void PrintTimeStamp();

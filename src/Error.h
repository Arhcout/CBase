#pragma once
#include <stdio.h>

#define LOG(...){fprintf(stderr, "[LOG] "); \
                PrintTimeStamp(); \
                fprintf(stderr, " %s:%s:%d: ", __FILE__, __func__, __LINE__); \
                fprintf(stderr, __VA_ARGS__);}(void)0

#define WARNING(...){fprintf(stderr, "[WARNING] "); \
                    PrintTimeStamp(); \
                    fprintf(stderr, " %s:%s:%d: ", __FILE__, __func__, __LINE__); \
                    fprintf(stderr, __VA_ARGS__);\
                    fprintf(stderr, "\033[0m");}(void)0

#define ERROR(...){fprintf(stderr, "[ERROR] "); \
                  PrintTimeStamp(); \
                  fprintf(stderr, " %s:%s:%d: ", __FILE__, __func__, __LINE__); \
                  fprintf(stderr, __VA_ARGS__);\
                  fprintf(stderr, "\033[0m");}(void)0

#define MALLOC_CHECK(val, failReturnValue) if(!(val)){ERROR("Out memory (malloc)");return (failReturnValue);}

void PrintTimeStamp();

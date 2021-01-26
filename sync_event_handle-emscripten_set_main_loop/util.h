#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <emscripten.h>

#if !defined(__UTIL__)
#define __UTIL__ 1
extern "C" {
EMSCRIPTEN_KEEPALIVE void print_time(char *str) {
  struct timeval myTime;
  struct tm *tm;
  gettimeofday(&myTime, NULL);
  tm = localtime(&myTime.tv_sec);
  printf("%s:%02d:%02d:%02d.%6d\n", str, tm->tm_hour, tm->tm_min, tm->tm_sec, myTime.tv_usec);
}
}
#endif /* __UTIL__ */

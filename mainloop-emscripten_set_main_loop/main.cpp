#include <stdio.h>
#include <time.h>
#include <emscripten.h>

void mainloop() {
  time_t t;
  struct tm tm;
  time(&t);
  localtime_r(&t, &tm);
  printf("call mainloop %02d:%02d:%02d\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
 }

int main(int argc, char** argv){
  emscripten_set_main_loop(mainloop, 0, 1);
//  emscripten_sleep(100); // 100ms スリープする
  return 0;
}


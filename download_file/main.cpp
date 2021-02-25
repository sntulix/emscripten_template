#include <emscripten.h>
#include <string.h>
 
int main(void) {
    const char* filename = "hello.txt";
    const char* text = "Hello world!";
//    EM_ASM_({ window.download($0, $1, $2) }, filename, text, strlen(text));
    return 0;
}

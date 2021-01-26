#include <stdio.h>
#include <emscripten.h>
#include "util.h"

EM_JS(void, process_event, (), {
	Module.ccall('print_time', '', ['string'], ["process event"]);
});

void mainloop() {
	print_time("before event handling.");
	process_event();
	print_time("after event handling.");
}

int main(int argc, char** argv){
	emscripten_set_main_loop(mainloop, 0, 1);
	return 0;
}


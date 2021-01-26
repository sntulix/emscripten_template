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
	while(1) {
		print_time("mainloop.");
		mainloop();
		emscripten_sleep(17);
	}
	return 0;
}


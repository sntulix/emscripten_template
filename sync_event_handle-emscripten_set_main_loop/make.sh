#!/bin/sh

emcc -s "EXPORTED_FUNCTIONS=['_main','_print_time']" -s "EXTRA_EXPORTED_RUNTIME_METHODS=['ccall','cwrap']" -s ASYNCIFY main.cpp -o index.html

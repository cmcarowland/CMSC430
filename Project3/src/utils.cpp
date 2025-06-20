#include <cstdarg>
#include <cstdio>
#include <string>

using namespace std;

void Echo(char* message) {
	#ifndef TESTING
	
	printf("%s", message);
	
	#endif
}

void Print(string format, ...) {
	#ifndef TESTING
	
	va_list args;
	va_start(args, format);
	vfprintf(stdout, format.c_str(), args);
	va_end(args);

	#endif
}

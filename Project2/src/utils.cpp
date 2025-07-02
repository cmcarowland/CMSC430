#include <cstdarg>
#include <cstdio>
#include <string>

using namespace std;
bool PRINT_RESULTS = false;

void Echo(char* message) {
	if(PRINT_RESULTS)
		printf("%s", message);
}
	

void Print(string format, ...) {
	if(PRINT_RESULTS) {	
		va_list args;
		va_start(args, format);
		vfprintf(stdout, format.c_str(), args);
		va_end(args);
	}
}
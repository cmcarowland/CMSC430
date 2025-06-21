/* 
   Raymond Rowland
   CMSC 430 Compiler Theory and Design
   Project 1 
   6/20/25

   This header file defines utility functions for the compiler project.
   It includes functions for printing messages and formatted output,
   which can be used for debugging and displaying results.
   The functions are conditionally compiled to exclude them during testing.
*/

#ifndef UTILS_H
#define UTILS_H

#include <cstdarg>

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

#endif
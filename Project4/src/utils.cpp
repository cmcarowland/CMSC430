/*
	Raymond Rowland
	CMSC 430 Compiler Theory and Design
	Project 4
	August 3, 2025

	utils.cpp

	Utility functions for the compiler project, including printing and echoing messages.
	Provides standardized output functionality for compilation results and debugging information.
*/

#include <cstdarg>
#include <cstdio>
#include <string>

using namespace std;
bool PRINT_RESULTS = true;

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

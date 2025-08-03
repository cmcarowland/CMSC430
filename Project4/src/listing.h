/*
	Raymond Rowland
	CMSC 430 Compiler Theory and Design
	Project 4
	August 3, 2025

	listing.h

	Header file declaring functions for compilation listing and error reporting.
	Provides interface for line management, error appending, and compilation
	summary generation used throughout the compiler's error tracking system.
*/

#include "error.h"
#include <string>

void firstLine();
void nextLine();
int* lastLine();
void appendError(ErrorCategories errorCategory, string message);
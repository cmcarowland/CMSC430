/*
	Raymond Rowland
	CMSC 430 Compiler Theory and Design
	Project 4
	August 3, 2025

	listing.cc

	Implements error tracking and reporting for the compiler project. 
	Manages line numbers, collects and categorizes errors (lexical, syntax, semantic, duplicate identifier, undeclared identifier), 
	and provides functions to display error summaries and details. 
	The Error class encapsulates error information and formatting for output.

	Modified from Project 3 to return error type counts to the caller.
*/

#include <cstdio>
#include <queue>

using namespace std;

#include "listing.h"

static int lineNumber;
static queue<Error*> errors;
static int errorCounts[] = {0, 0, 0, 0, 0}; // LEXICAL, SYNTAX, GENERAL_SEMANTIC, DUPLICATE_IDENTIFIER, UNDECLARED
static int totalErrors = 0;

static void displayErrors();
extern void Print(string format, ...);

void resetErrorCounts()
{
	for(int i = 0; i < 5; i++)
		errorCounts[i] = 0;
	totalErrors = 0;
}

void firstLine()
{
	resetErrorCounts();
	lineNumber = 1;
	Print("\n%4d  ",lineNumber);
}

void nextLine()
{
	displayErrors();
	lineNumber++;
	Print("%4d  ",lineNumber);
}

int* lastLine()
{
	Print("\n\n");
	if(totalErrors > 0)
	{
		Print("%d errors found. Compilation Failed!\n", totalErrors);
		Print("=========================================================\n");
		Print("Lexical Errors              : %d\n", errorCounts[LEXICAL]);
		Print("Syntactic Errors            : %d\n", errorCounts[SYNTAX]);
		Print("Semantic Errors             : %d\n", errorCounts[GENERAL_SEMANTIC]);
		Print("Duplicate Identifier Errors : %d\n", errorCounts[DUPLICATE_IDENTIFIER]);
		Print("Undeclared Identifier Errors: %d\n\n", errorCounts[UNDECLARED]);
		displayErrors();
	} else
		Print("Compiled Successfully!!!\n");
	
	return errorCounts;
}


void appendError(ErrorCategories errorCategory, string message)
{
	Error *error = new Error(lineNumber, errorCategory, message);
	errors.push(error);

	errorCounts[errorCategory]++;
	totalErrors++;
}

void displayErrors()
{
	while(errors.size() != 0)
	{
		Error *e = errors.front();
		e->Display();
		errors.pop();
	}
}

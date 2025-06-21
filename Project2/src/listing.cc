// CMSC 430 Compiler Theory and Design
// Project 1 Skeleton
// UMGC CITE
// Summer 2023

// This file contains the bodies of the functions that produces the 
// compilation listing

#include <cstdio>
#include <string>
#include <queue>

using namespace std;

#include "listing.h"

static int lineNumber;
static queue<Error*> errors;
static int errorCounts[] = {0, 0, 0, 0, 0}; // LEXICAL, SYNTAX, GENERAL_SEMANTIC, DUPLICATE_IDENTIFIER, UNDECLARED
static int totalErrors = 0;

static void displayErrors();
extern int Print(string format, ...);

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

int lastLine()
{
	Print("\n\n");
	if(totalErrors > 0)
	{
		Print("%d errors found. Compilation Failed!\n", totalErrors);
		Print("=========================================================\n");
		Print("Lexical Errors.             : %d\n", errorCounts[LEXICAL]);
		Print("Syntactic Errors            : %d\n", errorCounts[SYNTAX]);
		Print("Semantic Errors.            : %d\n", errorCounts[GENERAL_SEMANTIC]);
		Print("Duplicate Identifier Errors : %d\n", errorCounts[DUPLICATE_IDENTIFIER]);
		Print("Undeclared Identifier Errors: %d\n\n", errorCounts[UNDECLARED]);
		displayErrors();
	} else
		Print("Compiled Successfully!!!\n");
	
	return totalErrors;
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

Error::Error(int lineNumber, ErrorCategories errorCategory, string lineContent)
	: lineNumber(lineNumber), errorCategory(errorCategory) {
	this->lineContent = lineContent;
}

string Error::ErrorEnumToString(ErrorCategories errorCategory) const {
	switch (errorCategory) {
		case LEXICAL: return "Lexical Error";
		case SYNTAX: return "Syntax Error";
		case GENERAL_SEMANTIC: return "General Semantic Error";
		case DUPLICATE_IDENTIFIER: return "Duplicate Identifier Error";
		case UNDECLARED: return "Undeclared Identifier Error";
		default: return "Unknown Error";
	}
}

void Error::Display() const {
	Print("\t -%s : %s\n", ErrorEnumToString(errorCategory).c_str(), lineContent.c_str());
}
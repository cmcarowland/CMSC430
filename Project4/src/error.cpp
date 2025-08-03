/*
	Raymond Rowland
	CMSC 430 Compiler Theory and Design
	Project 4
	August 3, 2025

	error.cpp

	Implementation of Error class methods for compiler error handling.
	Provides error categorization, string conversion, and display functionality
	for lexical, syntax, semantic, duplicate identifier, and undeclared errors.
*/

#include "error.h"

extern void Print(string format, ...);

Error::Error(int lineNumber, ErrorCategories errorCategory, string lineContent)
	: lineNumber(lineNumber), errorCategory(errorCategory) {
	this->lineContent = lineContent;
}

string Error::ErrorEnumToString(ErrorCategories errorCategory) const {
	switch (errorCategory) {
		case LEXICAL: return "Lexical Error";
		case SYNTAX: return "Syntax Error";
		case GENERAL_SEMANTIC: return "Semantic Error";
		case DUPLICATE_IDENTIFIER: return "Duplicate Identifier Error";
		case UNDECLARED: return "Undeclared Identifier Error";
		default: return "Unknown Error";
	}
}

void Error::Display() const {
	Print("\t -%s : %s\n", ErrorEnumToString(errorCategory).c_str(), lineContent.c_str());
}
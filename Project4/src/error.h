/*
	Raymond Rowland
	CMSC 430 Compiler Theory and Design
	Project 4
	August 3, 2025

	error.h

	Header file defining Error class and ErrorCategories enumeration.
	Declares the interface for error handling, categorization, and display
	functionality used throughout the compiler for reporting various error types.
*/

#ifndef ERROR_H
#define ERROR_H

#include <string>
using namespace std;

enum ErrorCategories {LEXICAL, SYNTAX, GENERAL_SEMANTIC, DUPLICATE_IDENTIFIER,
	UNDECLARED};

class Error {
	protected:
		int lineNumber;
		string lineContent;
		ErrorCategories errorCategory;

		string ErrorEnumToString(ErrorCategories errorCategory) const;

	public:
		Error(int lineNumber, ErrorCategories errorCategory, string lineContent);
		void Display() const;
};

#endif
/*
	Raymond Rowland
	CMSC 430 Compiler Theory and Design
	Project 3
	July 20, 2025

	listing.h

	This header defines error handling utilities for the compiler project.
	It introduces error categories, error tracking functions, and an Error class
	to encapsulate error details such as line number, content, and category.
	The utilities help record, categorize, and display errors during compilation.
*/

enum ErrorCategories {LEXICAL, SYNTAX, GENERAL_SEMANTIC, DUPLICATE_IDENTIFIER,
	UNDECLARED};

void resetErrorCounts();
void firstLine();
void nextLine();
int lastLine();
void appendError(ErrorCategories errorCategory, string message);

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
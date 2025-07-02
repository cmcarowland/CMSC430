/*
    Raymond Rowland
	CMSC 430 Compiler Theory and Design
	Project 2 Skeleton
	July 1, 2025

	listing.h
	Header file for the listing functions
	including error messages.
*/

enum ErrorCategories {LEXICAL, SYNTAX, GENERAL_SEMANTIC, DUPLICATE_IDENTIFIER,
	UNDECLARED};

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
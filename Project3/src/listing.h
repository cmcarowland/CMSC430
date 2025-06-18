// CMSC 430 Compiler Theory and Design
// Project 3 Skeleton
// UMGC CITE
// Summer 2023

// This file contains the function prototypes for the functions that produce
// the compilation listing

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
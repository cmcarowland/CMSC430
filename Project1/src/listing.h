/* 
   Raymond Rowland
   CMSC 430 Compiler Theory and Design
   Project 1 
   6/20/25

	The header file defines the error handling and listing functionality for the compiler.
    It declares functions for managing line numbers, collecting errors, and displaying error summaries.
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
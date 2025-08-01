/* CMSC 430 Compiler Theory and Design
   Project 4 Skeleton
   UMGC CITE
   Summer 2023
   
   Project 4 Parser with semantic actions for static semantic errors */

%{
#include <string>
#include <vector>
#include <deque>
#include <map>

using namespace std;

#include "types.h"
#include "listing.h"
#include "symbols.h"

int yylex();
Types find(Symbols<Types>& table, CharPtr identifier, string tableName);
void yyerror(const char* message);

Symbols<Types> scalars;
Symbols<Types> lists;

double result;
deque<double> args;
#define YYDEBUG 1

%}

%define parse.error verbose

%union {
	CharPtr iden;
	Types type;
}

%token <iden> IDENTIFIER

%token <type> INT_LITERAL CHAR_LITERAL REAL_LITERAL

%token <oper> ADDOP MULOP ANDOP RELOP MODOP EXPOP NEGOP NOTOP OROP

%token <dir> LEFT RIGHT

%type <type> list expressions body type statement_ statement cases case expression
	primary neg mul mod exp elseif elseifs list_choice function function_header

%token BEGIN_ CHARACTER FUNCTION END INTEGER IS LIST OF 
	RETURNS SWITCH CASE OTHERS ENDSWITCH WHEN FOLD ENDFOLD 
	IF ELSIF ELSE ENDIF THEN REAL ARROW 

%%

function:	
	function_header optional_variable body  { checkAssignment($1, $3, "Return Type"); }
	| error { $$ = MISMATCH; }
;	
		
function_header:	
	FUNCTION IDENTIFIER RETURNS type ';' { $$ = $4; }
;

type:
	INTEGER {$$ = INT_TYPE;} 
	| CHARACTER {$$ = CHAR_TYPE; }
	| REAL {$$ = REAL_TYPE; }
;

optional_variable:
	optional_variable variable
	| %empty 
;
    
variable:	
	IDENTIFIER ':' type IS statement ';' { 
		Types scalar;
		if(scalars.find($1, scalar)){
			string s = "Scalar already defined: " + string($1);
			appendError(GENERAL_SEMANTIC, s.c_str());
		} else {
			checkAssignment($3, $5, "Variable Initialization"); 
			scalars.insert($1, $3); 
		}
	}
	| IDENTIFIER ':' LIST OF type IS list ';' { 
		Types list;
		if(lists.find($1, list)){
			string s = "List already defined: " + string($1);
			appendError(GENERAL_SEMANTIC, s.c_str());
		} else {
			checkList($5, $7); 
			lists.insert($1, $5); 
		}
	}
;

list:
	'(' expressions ')' { $$ = $2; } 
;

expressions:
	expressions ',' expression { $$ = checkListItem($1, $3); } 
	| expression
;

body:
	BEGIN_ statement_ END ';' { $$ = $2;} 
	| error { $$ = NONE; }
;
    
statement_:
	statement ';' { $$ = $1; }
	| error ';' { $$ = MISMATCH; } 
;
	
statement:
	expression
	| WHEN condition ',' expression ':' expression 
		{$$ = checkWhen($4, $6);}
	| SWITCH expression IS cases OTHERS ARROW statement_ ENDSWITCH 
		{$$ = checkSwitch($2, $4, $7);} 
	| IF condition THEN statement_ { cacheIf($4); } elseifs ELSE statement_ { $<type>$ = areSameTypes($8); } ENDIF 
		{ clearCache(); $$ = $<type>9; }
	| FOLD direction operator list_choice { $<type>$ = $4; } ENDFOLD { $$ = $<type>5; }
	| FOLD error ENDFOLD { $$ = NONE; }
;

list_choice:
	list { $$ = checkFold($1); }
	| IDENTIFIER {
		Types list = NONE;
		if (!lists.find($1, list)) {
			string s = "Undeclared List: " + string($1);
			appendError(GENERAL_SEMANTIC, s.c_str());
			YYERROR;
		}
		
		$$ = checkFold(list);
	}
;

direction:
	LEFT
	| RIGHT
;

operator:
	ADDOP 
	| MULOP 
;

elseifs:
	elseifs elseif { $$ = $2; }
	| %empty { $$ = NONE; }
;

elseif:
	ELSIF condition THEN statement_ { $$ = areSameTypes($4); }
;

cases:
	cases case {$$ = checkCases($1, $2);}
	| %empty {$$ = NONE;} 
;
	
case:
	CASE INT_LITERAL ARROW statement ';' {$$ = $4;} 
; 

condition:
	condition ANDOP relation
	| relation 
;

relation:
	'(' condition ')'
	| expression RELOP expression { checkRelopTypes($1, $3); }
;

neg:
	NEGOP neg {$$ = checkNumericType($2); }
	| primary { $$ = $1; }
;

exp:
	neg { $$ = $1; }
	| exp EXPOP neg { $$ = checkArithmetic($1, $3); }
;

mod:
	exp { $$ = $1; }
	| mod MODOP exp { $$ = checkMod($1, $3); }
;

mul:
	mod { $$ = $1; }
	| mul MULOP mod { $$ = checkArithmetic($1, $3); }
;

expression:
	mul { $$ = $1; }
	| expression ADDOP mul { $$ = checkArithmetic($1, $3); }
;

primary:
	'(' expression ')' {$$ = $2;}
	| INT_LITERAL
	| CHAR_LITERAL
	| REAL_LITERAL
	| IDENTIFIER '(' expression ')' { 
		if(checkSubscript($3) == INT_TYPE){ 
			Types t = find(lists, $1, "List"); 
			if(t == MISMATCH)
			{
				string s = "Undeclared List: " + string($1);
				appendError(GENERAL_SEMANTIC, s.c_str());
			}
			$$ = t;
		} else { 
			$$ = MISMATCH;
		}
	}
	| IDENTIFIER  {
		Types t = find(scalars, $1, "Scalar");
		if(t == MISMATCH){
			string s = "Undeclared Scalar: " + string($1);
			appendError(GENERAL_SEMANTIC, s.c_str());
		}
		$$ = t;
	} 
;

%%

Types find(Symbols<Types>& table, CharPtr identifier, string tableName) {
	Types type;
	if (!table.find(identifier, type)) {
		//appendError(UNDECLARED, tableName + " " + identifier);
		return MISMATCH;
	}
	return type;
}

void yyerror(const char* message) {
	appendError(SYNTAX, message);
}

extern int* parse() {
	scalars = Symbols<Types>();
	lists = Symbols<Types>();
	yydebug = 0;
	firstLine();
	yyparse();
	return lastLine();
	
}

#ifndef TESTING
int main(int argc, char *argv[]) {
	int* errors = parse();
	int totalErrors = 0;
	for(int i = 0; i < 5; i++)
		totalErrors += errors[i];

	return totalErrors;
} 
#endif
/* CMSC 430 Compiler Theory and Design
   Project 3 
   UMGC CITE
   Summer 2023
   
   Project 3 Parser with semantic actions for the interpreter */

%{

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>

using namespace std;

#include "values.h"
#include "listing.h"
#include "symbols.h"

int yylex();
void yyerror(const char* message);
double extract_element(CharPtr list_name, double subscript);

Symbols<double> scalars;
Symbols<vector<double>*> lists;
double result;

#define YYDEBUG 1
%}

%define parse.error verbose

%union {
	CharPtr iden;
	Operators oper;
	double value;
	vector<double>* list;
}

%token <iden> IDENTIFIER

%token <value> INT_LITERAL CHAR_LITERAL REAL_LITERAL

%token <oper> ADDOP MULOP ANDOP RELOP MODOP EXPOP NEGOP NOTOP OROP

%token ARROW

%token BEGIN_ CHARACTER FUNCTION END INTEGER IS LIST OF 
	RETURNS SWITCH CASE OTHERS ENDSWITCH WHEN FOLD ENDFOLD 
	IF ELSIF ELSE ENDIF THEN LEFT RIGHT REAL

%type <value> body statement_ statement cases case expression primary
	 condition relation add mul exp neg

%type <list> list expressions

%%

function:	
	function_header optional_variables body ';' {result = $3;} ;
	
function_header:	
	FUNCTION IDENTIFIER RETURNS type ';' ;

type:
	INTEGER |
	CHARACTER |
	REAL
;
	
optional_variables:
	optional_variables variable
	| %empty 
;
	
variable:	
	IDENTIFIER ':' type IS statement ';' {scalars.insert($1, $5);}; |
	IDENTIFIER ':' LIST OF type IS list ';' {lists.insert($1, $7);} ;

list:
	'(' expressions ')' {$$ = $2;} ;

expressions:
	expressions ',' expression {$1->push_back($3); $$ = $1;} | 
	expression {$$ = new vector<double>(); $$->push_back($1);}

body:
	BEGIN_ statement_ END {$$ = $2;} ;

statement_:
	statement ';' |
	error ';' {$$ = 0;} ;

list_choice:
	list
	| IDENTIFIER
;

statement:
	expression
	| WHEN condition ',' expression ':' expression {$$ = $2 ? $4 : $6;} 
	| SWITCH expression IS cases OTHERS ARROW statement ';' ENDSWITCH
		{$$ = !isnan($4) ? $4 : $7;} 
	| IF condition THEN statement elseifs ELSE statement ENDIF ';' 
		{$$ = $2 ? $4 : $7;}
	| FOLD direction operator list_choice ENDFOLD ';' {$$ = -1;}
;

elseif:
	ELSIF condition THEN statement
;

elseifs:
	elseifs elseif
	| %empty
;

direction:
	LEFT
	| RIGHT
;

operator:
	ADDOP
	| MULOP
;

cases:
	cases case {$$ = !isnan($1) ? $1 : $2;} |
	%empty {$$ = NAN;} ;
	
case:
	CASE INT_LITERAL ARROW statement ';' {$$ = $<value>-2 == $2 ? $4 : NAN;} ; 

condition:
	condition ANDOP relation {$$ = $1 && $2;} |
	relation ;

relation:
	'(' condition ')' {$$ = $2;} |
	expression RELOP expression {$$ = evaluateRelational($1, $2, $3);} ;

neg:
	NEGOP neg {$$ = -$2;}
	| primary {$$ = $1;}
;

exp:
	neg {$$ = $1;}
	| neg EXPOP exp {$$ = pow($1, $3);}
;

mul:
	exp {$$ = $1;}
	| mul MULOP exp {$$ = evaluateArithmetic($1, $2, $3);}
;

add:
	mul {$$ = $1;}
	| add ADDOP mul {$$ = evaluateArithmetic($1, $2, $3);}
;

expression:
	add {$$ = $1;}
;

primary:
	'(' expression ')' {$$ = $2;} |
	INT_LITERAL | 
	REAL_LITERAL |
	CHAR_LITERAL |
	IDENTIFIER '(' expression ')' {$$ = extract_element($1, $3); } |
	IDENTIFIER {if (!scalars.find($1, $$)) appendError(UNDECLARED, $1);} ;

%%

void yyerror(const char* message) {
	appendError(SYNTAX, message);
}

double extract_element(CharPtr list_name, double subscript) {
	vector<double>* list; 
	if (lists.find(list_name, list))
		return (*list)[subscript];
	appendError(UNDECLARED, list_name);
	return NAN;
}

extern double parse() {
	//yydebug = 1;
	firstLine();
	yyparse();
	if (lastLine() == 0)
		cout << "Result = " << result << endl;
	return result;
}

#ifndef TESTING
int main(int argc, char *argv[]) {
	parse();
	return 0;
}
#endif
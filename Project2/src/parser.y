/*
   Raymond Rowland
	CMSC 430 Compiler Theory and Design
	Project 2 Skeleton
	July 1, 2025 

	parser.y
	This file contains the parser for the compiler.
	It uses bison to generate the parser code.
	The parser reads the tokens produced by the scanner.
*/

%{

#include <string>

using namespace std;

#include "listing.h"
#define YYDEBUG 1
int yylex();
void yyerror(const char* message);
int yyerrstatus;
%}

%define parse.error verbose

%token IDENTIFIER INT_LITERAL CHAR_LITERAL

%token ADDOP MULOP ANDOP RELOP ARROW

%token BEGIN_ CASE CHARACTER ELSE END ENDSWITCH

%token FUNCTION INTEGER IS LIST OF OTHERS RETURNS SWITCH WHEN

%token REAL MODOP EXPOP NEGOP NOTOP OROP ELSIF 
	
%token ENDFOLD ENDIF FOLD IF THEN LEFT RIGHT 
%token REAL_LITERAL

%%

function:	
	function_header optional_variables body 
	| error ';'
;

optional_variables:
	optional_variables variable
	| %empty 
;

variable:	
	IDENTIFIER ':' type IS statement_
	| IDENTIFIER ':' LIST OF type IS list ';' 
	| error ';'
;

function_header:	
	FUNCTION IDENTIFIER parameters RETURNS type ';' 
;

parameters:
	parameter ',' parameters
	| parameter
	| %empty
;

parameter:
	IDENTIFIER ':' type
	| error
;

type:
	INTEGER |
	CHARACTER |
	REAL
;
	
list:
	'(' expressions ')' 
;

expressions:
	expression
	| expressions ',' expression
;

body:
	BEGIN_ statement_ END ';' ;
    
statement_:
	statement ';'
;

statement:
	expression
	| WHEN condition ',' expression ':' expression
	| SWITCH expression IS cases OTHERS ARROW statement_ ENDSWITCH
	| IF condition THEN statement_ elseifs ELSE statement_ ENDIF
	| FOLD direction operator list_choice ENDFOLD
;

elseif:
	ELSIF condition THEN statement_
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

list_choice:
	list
	| IDENTIFIER
;

case:
	CASE expression ARROW statement_
; 

cases:
	cases case
	| %empty 
;	

rel_condition:
	NOTOP rel_condition
	| '(' condition ')'
	| expression RELOP expression
;

and:
	rel_condition
	| and ANDOP rel_condition
;

or:
	and
	| or OROP and
;

condition:
	or
;

neg:
	NEGOP neg
	| primary
;

exp:
	neg
	| neg EXPOP exp
;

mul:
	exp
	| mul MULOP exp
	| mul MODOP exp
;

add:
	mul
	| add ADDOP mul
;

expression:
	add
;

primary:
	'(' expression ')'
	| INT_LITERAL 
	| REAL_LITERAL 
	| CHAR_LITERAL
	| IDENTIFIER '(' expression ')'
	| IDENTIFIER
	| error
;

%%

void yyerror(const char* message) {
	appendError(SYNTAX, message);
}

double parse()
{
	//yydebug=1;
	firstLine();
	yyparse();
	return lastLine();
}

#ifndef TESTING
int main(int argc, char *argv[]) {
	parse();	
} 
#endif
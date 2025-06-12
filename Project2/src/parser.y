/* CMSC 430 Compiler Theory and Design
   Project 2 Skeleton
   UMGC CITE
   Summer 2023 

   Project 2 Parser */

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
;

optional_variables:
	optional_variables variable
	| %empty 
;

variable:	
	IDENTIFIER ':' type IS statement
	| IDENTIFIER ':' LIST OF type IS list ';' 
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
	statement
	| error 
;

statement:
	expression ';'
	| WHEN condition ',' expression ':' expression ';'
	| SWITCH expression IS cases OTHERS ARROW statement ENDSWITCH ';'
	| IF condition THEN statement elseifs ELSE statement ENDIF ';'
	| FOLD direction operator list_choice ENDFOLD ';'
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

list_choice:
	list
	| IDENTIFIER
;

case:
	CASE expression ARROW statement 
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
;

%%

void yyerror(const char* message) {
	appendError(SYNTAX, message);
}

int main(int argc, char *argv[]) {
	//yydebug=1;
	firstLine();
	yyparse();
	return lastLine();
} 

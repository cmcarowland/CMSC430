/* CMSC 430 Compiler Theory and Design
   Project 2 Skeleton
   UMGC CITE
   Summer 2023 

   Project 2 Parser */

%{

#include <string>

using namespace std;

#include "listing.h"
//#define YYDEBUG 1
int yylex();
void yyerror(const char* message);

%}

%define parse.error verbose

%token IDENTIFIER INT_LITERAL CHAR_LITERAL

%token ADDOP MULOP ANDOP RELOP ARROW

%token BEGIN_ CASE CHARACTER ELSE END ENDSWITCH

%token FUNCTION INTEGER IS LIST OF OTHERS RETURNS SWITCH WHEN

%token REAL REMOP EXPOP NEGOP NOTOP OROP ELSIF MODOP
	
%token ENDFOLD ENDIF FOLD IF THEN LEFT RIGHT 
%token REAL_LITERAL HEX_LITERAL

%%

function:	
	function_header optional_variables body 
;

optional_variables:
	optional_variables variable
	| variable
	| %empty 
;

variable:	
	IDENTIFIER ':' type IS statement |
	IDENTIFIER ':' LIST OF type IS list ';' 
;

function_header:	
	FUNCTION IDENTIFIER parameters RETURNS type ';'  
;

parameters:
	parameters ',' parameter
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
	expressions ',' expression
	| expression ;

body:
	BEGIN_ statement END ';' 
;
    
statement:
	expression ';'
	| WHEN condition ',' expression ':' expression ';'
	| SWITCH expression IS cases OTHERS ARROW statement ENDSWITCH ';'
	| IF condition THEN statement elseifs ELSE statement ENDIF ';'
	| FOLD direction operator list_choice ENDFOLD ';'
;

elseifs:
	elseifs ELSIF condition THEN statement |
	ELSIF condition THEN statement |
	%empty
;

cases:
	cases case |
	case 
;
	
case:
	CASE INT_LITERAL ARROW statement 
; 

direction:
	LEFT | RIGHT
;

list_choice:
	list 
	| IDENTIFIER
;

operator:
	ADDOP 
	| MULOP
;

condition:
	condition ANDOP relation |
	relation ;

relation:
	'(' condition ')' |
	expression RELOP expression 
;

arithmetic_operator:
	ADDOP | MULOP | EXPOP | MODOP 
;

//logical_operator:
//	ANDOP | OROP | NOTOP
//;

expression:
	'(' expression ')'
	| expression arithmetic_operator expression
	| INT_LITERAL 
	| CHAR_LITERAL 
	| REAL_LITERAL
	| IDENTIFIER '(' expression ')'
	| IDENTIFIER
; 

%%

void yyerror(const char* message) {
	appendError(SYNTAX, message);
}

int main(int argc, char *argv[]) {
	//#ifdef YYDEBUG
  	//	yydebug = 1;
	//#endif

	firstLine();
	yyparse();
	lastLine();
	return 0;
} 

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
#include <deque>
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
deque<double> args;

#define YYDEBUG 1
%}

%define parse.error verbose

%union {
	CharPtr iden;
	Operators oper;
	double value;
	vector<double>* list;
	Direction dir;
}

%token <iden> IDENTIFIER

%token <value> INT_LITERAL CHAR_LITERAL REAL_LITERAL

%token <oper> ADDOP MULOP ANDOP RELOP MODOP EXPOP NEGOP NOTOP OROP

%token <dir> LEFT RIGHT

%token BEGIN_ CHARACTER FUNCTION END INTEGER IS LIST OF 
	RETURNS SWITCH CASE OTHERS ENDSWITCH WHEN FOLD ENDFOLD 
	IF ELSIF ELSE ENDIF THEN REAL ARROW


%type <value> body statement_ statement cases case expression primary
	add mul exp neg 
	condition and or rel_condition elseifs elseif FOLD

%type <list> list expressions list_choice

%type <dir> direction
%type <oper> operator

%%

function:	
	function_header optional_variables body ';' {result = $3;} 
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
	IDENTIFIER ':' type {
		if(args.empty()) return -1;  
		double val = args.front(); 
		printf("\nPopped %lf\n", val); 
		args.pop_front(); 
		scalars.insert($1, val);
	}
;

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
	IDENTIFIER ':' type IS statement_ {scalars.insert($1, $5);} 
	| IDENTIFIER ':' LIST OF type IS list ';' {lists.insert($1, $7);} 
;

list:
	'(' expressions ')' {$$ = $2;} 
;

expressions:
	expressions ',' expression {$1->push_back($3); $$ = $1;} | 
	expression {$$ = new vector<double>(); $$->push_back($1);}

body:
	BEGIN_ statement_ END {$$ = $2;} 
;

statement_:
	statement ';'
	| error ';' {$$ = 0;} 
;

list_choice:
	list 
	| IDENTIFIER {
		vector<double>* list;
		if (lists.find($1, list)) {
			$$ = list;
		} else {
			appendError(UNDECLARED, $1);
			$$ = new vector<double>();
		}
	}
;

statement:
	expression
	| WHEN condition ',' expression ':' expression {$$ = $2 ? $4 : $6;} 
	| SWITCH expression IS cases OTHERS ARROW statement_ ENDSWITCH {$$ = !isnan($4) ? $4 : $7;} 
	| IF condition THEN statement_ elseifs ELSE statement_ ENDIF {$$ = $2 ? $4 : $5 ? $5 : $7;}
	| FOLD direction operator list_choice ENDFOLD {$$ = evaluateFold($2, $3, $4);}
;

elseif:
	ELSIF condition THEN statement_ {$$ = $2 ? $4 : 0;}
;

elseifs:
	elseif elseifs {$$ = $1 ? $1 : $2;}
	| %empty {$$ = 0;}
;

operator:
	ADDOP 
	| MULOP 
;

direction:
	LEFT
	| RIGHT
;

cases:
	cases case {$$ = !isnan($1) ? $1 : $2;} |
	%empty {$$ = NAN;} ;
	
case:
	CASE INT_LITERAL ARROW statement ';' {$$ = $<value>-2 == $2 ? $4 : NAN;} ; 


rel_condition:
	NOTOP rel_condition {$$ = !$2;}
	| '(' condition ')' {$$ = $2;}
	| expression RELOP expression {$$ = evaluateRelational($1, $2, $3);}
;

and:
	rel_condition {$$ = $1;}
	| and ANDOP rel_condition {$$ = evaluateRelational($1, $2, $3);}
;

or:
	and {$$ = $1;}
	| or OROP and {$$ = evaluateRelational($1, $2, $3);}
;

condition:
	or {$$ = $1;}
;

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
	yydebug = 0;
	firstLine();
	yyparse();
	if (lastLine() == 0)
		cout << "Result = " << result << endl;
	return result;
}

#ifndef TESTING
int main(int argc, char *argv[]) {
	if(argc > 1)
	{
		for(int i = 1; i < argc; i++)
		{
			args.push_back(atof(argv[i]));
		}
	}

	parse();
	return 0;
}
#endif
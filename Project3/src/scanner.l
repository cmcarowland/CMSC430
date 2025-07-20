/*
	Raymond Rowland
	CMSC 430 Compiler Theory and Design
	Project 3
	July 20, 2025

   scanner.l

   Lexical analyzer for our simple functional programming language.
   Recognizes keywords, identifiers, literals, operators, and punctuation.
   Handles comments and whitespace appropriately.
   Uses Flex for lexical analysis.
   
*/

/* This file contains flex input file */

%{
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

#include "values.h"
#include "listing.h"
#include "tokens.h"
extern void Echo(char *);

%}

%option noyywrap

ws		      [ \t\r]+
comment		"//".*\n
line_cmt    "--".*\n
line		   [\n]
id		      [A-Za-z](_{0,2}[A-Za-z0-9])*
digit		   [0-9]
hexValue    #{1}[0-9a-fA-F]+
double      [+-]?{digit}*\.{1}{dec}(?:[Ee]?[+-]?{dec})?
dec		    {digit}+
escape		'\\[nrftb]'
eqop        (<|=|<>|>|>=|<=)
char		'.'
punc		[\(\),:;]
%%

{ws}        { Echo(yytext); }
{comment}   { Echo(yytext); nextLine(); }
{line_cmt}  { Echo(yytext); nextLine(); }
{line}      { Echo(yytext); nextLine(); }
"+"         { Echo(yytext); yylval.oper = ADD; return(ADDOP); }
"-"         { Echo(yytext); yylval.oper = SUBTRACT; return(ADDOP); }
"*"         { Echo(yytext); yylval.oper = MULTIPLY; return(MULOP); }
"/"         { Echo(yytext); yylval.oper = DIVIDE; return(MULOP); }
"%"         { Echo(yytext); yylval.oper = MODULO; return(MULOP); }
"^"         { Echo(yytext); yylval.oper = POWER; return(EXPOP); }
"~"         { Echo(yytext); yylval.oper = NEGATE; return(NEGOP); }
"&"         { Echo(yytext); yylval.oper = AND; return(ANDOP); }
{eqop}      { Echo(yytext); yylval.oper = 
               (strcmp(yytext, "<") == 0) ? LESS :
               (strcmp(yytext, "<=") == 0) ? LESS_EQ :
               (strcmp(yytext, ">") == 0) ? GREATER :
               (strcmp(yytext, ">=") == 0) ? GREATER_EQ :
               (strcmp(yytext, "=") == 0) ? EQUAL :
               (strcmp(yytext, "<>") == 0) ? NOT_EQUAL : UNKNOWN;
               return(RELOP); 
            }
"=>"        { Echo(yytext); return(ARROW); }
"|"         { Echo(yytext); yylval.oper = OR; return(OROP); }
"!"         { Echo(yytext); yylval.oper = NOT; return(NOTOP); }
begin       { Echo(yytext); return(BEGIN_); }
case        { Echo(yytext); return(CASE); }
character   { Echo(yytext); return(CHARACTER); }
end         { Echo(yytext); return(END); }
endswitch   { Echo(yytext); return(ENDSWITCH); }
function    { Echo(yytext); return(FUNCTION); }
integer     { Echo(yytext); return(INTEGER); }
is          { Echo(yytext); return(IS); }
list        { Echo(yytext); return(LIST); }
of          { Echo(yytext); return(OF); }
others      { Echo(yytext); return(OTHERS); }
returns     { Echo(yytext); return(RETURNS); }
switch      { Echo(yytext); return(SWITCH); }
when        { Echo(yytext); return(WHEN); }

else        { Echo(yytext); return(ELSE); }
elsif       { Echo(yytext); return(ELSIF); }
endfold     { Echo(yytext); return(ENDFOLD); }
endif       { Echo(yytext); return(ENDIF); }
fold        { Echo(yytext); return(FOLD); }
if          { Echo(yytext); return(IF); }
left        { Echo(yytext); yylval.dir = Direction::FOLD_LEFT; return(LEFT); }
real        { Echo(yytext); return(REAL); }
right       { Echo(yytext); yylval.dir = Direction::FOLD_RIGHT; return(RIGHT); }
then        { Echo(yytext); return(THEN); }
{escape}    { Echo(yytext);
               // Map escape sequences to ASCII values
               switch (yytext[2]) {
                  case 'n': yylval.value = '\n'; break;
                  case 'r': yylval.value = '\r'; break;
                  case 'f': yylval.value = '\f'; break;
                  case 't': yylval.value = '\t'; break;
                  case 'b': yylval.value = '\b'; break;
                  default:  yylval.value = -1; break;
               }
               return(CHAR_LITERAL);
            }

{id}		   { Echo(yytext); yylval.iden = (CharPtr)malloc(yyleng + 1); 
			   strcpy(yylval.iden, yytext); return(IDENTIFIER);}
{dec}		   { Echo(yytext); yylval.value = atoi(yytext); return(INT_LITERAL); }
{double}	   { Echo(yytext); yylval.value = atof(yytext); return(REAL_LITERAL); }
{hexValue}  { Echo(yytext); yylval.value = strtol(yytext+1, NULL, 16); return(INT_LITERAL); }
{char}		{ Echo(yytext); yylval.value = yytext[1]; return(CHAR_LITERAL); }
{punc}		{ Echo(yytext); return(yytext[0]); }
.		      { Echo(yytext); appendError(LEXICAL, yytext); }
%%


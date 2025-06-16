/* CMSC 430 Compiler Theory and Design
   Project 3 Skeleton
   UMGC CITE
   Summer 2023 */

/* This file contains flex input file */

%{
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

#include "values.h"
#include "listing.h"
#include "tokens.h"

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

{ws}        { ECHO; }
{comment}   { ECHO; nextLine(); }
{line_cmt}  { ECHO; nextLine(); }
{line}      { ECHO; nextLine(); }
"+"         { ECHO; yylval.oper = ADD; return(ADDOP); }
"-"         { ECHO; yylval.oper = SUBTRACT; return(ADDOP); }
"*"         { ECHO; yylval.oper = MULTIPLY; return(MULOP); }
"/"         { ECHO; yylval.oper = DIVIDE; return(MULOP); }
"%"         { ECHO; yylval.oper = MODULO; return(MULOP); }
"^"         { ECHO; yylval.oper = POWER; return(EXPOP); }
"~"         { ECHO; yylval.oper = NEGATE; return(NEGOP); }
"&"         { ECHO; yylval.oper = AND; return(ANDOP); }
{eqop}      { ECHO; yylval.oper = 
               (strcmp(yytext, "<") == 0) ? LESS :
               (strcmp(yytext, "<=") == 0) ? LESS_EQ :
               (strcmp(yytext, ">") == 0) ? GREATER :
               (strcmp(yytext, ">=") == 0) ? GREATER_EQ :
               (strcmp(yytext, "=") == 0) ? EQUAL :
               (strcmp(yytext, "<>") == 0) ? NOT_EQUAL : UNKNOWN;
               return(RELOP); 
            }
"=>"        { ECHO; return(ARROW); }
"|"         { ECHO; yylval.oper = OR; return(OROP); }
"!"         { ECHO; yylval.oper = NOT; return(NOTOP); }
begin       { ECHO; return(BEGIN_); }
case        { ECHO; return(CASE); }
character   { ECHO; return(CHARACTER); }
end         { ECHO; return(END); }
endswitch   { ECHO; return(ENDSWITCH); }
function    { ECHO; return(FUNCTION); }
integer     { ECHO; return(INTEGER); }
is          { ECHO; return(IS); }
list        { ECHO; return(LIST); }
of          { ECHO; return(OF); }
others      { ECHO; return(OTHERS); }
returns     { ECHO; return(RETURNS); }
switch      { ECHO; return(SWITCH); }
when        { ECHO; return(WHEN); }

else        { ECHO; return(ELSE); }
elsif       { ECHO; return(ELSIF); }
endfold     { ECHO; return(ENDFOLD); }
endif       { ECHO; return(ENDIF); }
fold        { ECHO; return(FOLD); }
if          { ECHO; return(IF); }
left        { ECHO; return(LEFT); }
real        { ECHO; return(REAL); }
right       { ECHO; return(RIGHT); }
then        { ECHO; return(THEN); }
{escape}    { ECHO;
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

{id}		   { ECHO; yylval.iden = (CharPtr)malloc(yyleng + 1); 
			   strcpy(yylval.iden, yytext); return(IDENTIFIER);}
{dec}		   { ECHO; yylval.value = atoi(yytext); return(INT_LITERAL); }
{double}	   { ECHO; yylval.value = atof(yytext); return(REAL_LITERAL); }
{hexValue}  { ECHO; yylval.value = strtol(yytext+1, NULL, 16); return(INT_LITERAL); }
{char}		{ ECHO; yylval.value = yytext[1]; return(CHAR_LITERAL); }
{punc}		{ ECHO; return(yytext[0]); }
.		      { ECHO; appendError(LEXICAL, yytext); }
%%


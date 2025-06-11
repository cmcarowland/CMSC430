/* CMSC 430 Compiler Theory and Design
   Project 2 Skeleton
   UMGC CITE
   Summer 2023 */

/* This file contains flex input file */

%{
#include <cstdio>
#include <string>

using namespace std;

#include "listing.h"
#include "tokens.h"

%}

%option noyywrap

ws		    [ \t\r]+
comment		"//".*\n
line_cmt    "--".*\n
line		[\n]
id		    [A-Za-z](_{0,2}[A-Za-z0-9])*
digit		[0-9]
hexValue    #{1}[0-9a-fA-F]+
double      [+-]?{digit}*\.{1}{dec}(?:[Ee]?[+-]?{dec})?
dec		    {digit}+
escape		'\\[nrftb]'
eqop        (<|=|<>|>|>=|<=)
char		'.'
punc		[\(\),:;]

%%

{ws}		{ ECHO; }
{comment}	{ ECHO; nextLine(); }
{line_cmt}  { ECHO; nextLine(); }
{line}		{ ECHO; nextLine(); }
"+"			{ ECHO; return(ADDOP); }
"-"			{ ECHO; return(ADDOP); }
"*"			{ ECHO; return(MULOP); }
"/"			{ ECHO; return(MULOP); }
"%"			{ ECHO; return(REMOP); }
"^"			{ ECHO; return(EXPOP); }
"~"			{ ECHO; return(NEGOP); }
"&"			{ ECHO; return(ANDOP); }
{eqop}		{ ECHO; return(RELOP); }
"=>"		{ ECHO; return(ARROW); }
"|"			{ ECHO; return(OROP); }
"!"			{ ECHO; return(NOTOP); }
begin		{ ECHO; return(BEGIN_); }
case		{ ECHO; return(CASE); }
character	{ ECHO; return(CHARACTER); }
end			{ ECHO; return(END); }
endswitch	{ ECHO; return(ENDSWITCH); }
function	{ ECHO; return(FUNCTION); }
integer		{ ECHO; return(INTEGER); }
is			{ ECHO; return(IS); }
list		{ ECHO; return(LIST); }
of			{ ECHO; return(OF); }
others		{ ECHO; return(OTHERS); }
returns		{ ECHO; return(RETURNS); }
switch		{ ECHO; return(SWITCH); }
when		{ ECHO; return(WHEN); }

else 		{ ECHO; return(ELSE); }
elsif 		{ ECHO; return(ELSIF); }
endfold 	{ ECHO; return(ENDFOLD); }
endif 		{ ECHO; return(ENDIF); }
fold 		{ ECHO; return(FOLD); }
if 			{ ECHO; return(IF); }
left		{ ECHO; return(LEFT); }
real 		{ ECHO; return(REAL); }
right 		{ ECHO; return(RIGHT); }
then 		{ ECHO; return(THEN); }
{escape} 	{ ECHO; return (CHAR_LITERAL); }

{id}		{ ECHO; return(IDENTIFIER);}
{dec}		{ ECHO; return(INT_LITERAL); }
{double}	{ ECHO; return(REAL_LITERAL); }
{hexValue}  { ECHO; return (HEX_LITERAL); }
{char}		{ ECHO; return(CHAR_LITERAL); }
{punc}		{ ECHO; return(yytext[0]); }
.		    { ECHO; appendError(LEXICAL, yytext); }
%%

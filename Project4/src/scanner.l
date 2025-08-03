/*
	Raymond Rowland
	CMSC 430 Compiler Theory and Design
	Project 4
	August 3, 2025

	scanner.l

	Flex lexical analyzer specification for the compiler project.
	Defines token patterns, keywords, operators, literals, and identifiers.
	Handles lexical analysis including error reporting for invalid characters.
*/



%{
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

#include "types.h"
#include "listing.h"
#include "tokens.h"

extern void Echo(char *);

%}

%option noyywrap

ws         [ \t\r]+
comment    "//".*\n
line_cmt   "--".*\n
line       [\n]
id         [A-Za-z](_{0,2}[A-Za-z0-9])*
digit      [0-9]
hexValue   #{1}[0-9a-fA-F]+
double     [+-]?{digit}*\.{1}{dec}(?:[Ee]?[+-]?{dec})?
dec        {digit}+
escape     '\\[nrftb]'
eqop       (<|=|<>|>|>=|<=)
char       '.'
punc       [\(\),:;]

%%

{ws}           { Echo(yytext); }
{comment}      { Echo(yytext); nextLine(); }
{line_cmt}     { Echo(yytext); nextLine(); }
{line}         { Echo(yytext); nextLine(); }
"+"            { Echo(yytext); return(ADDOP); }
"*"            { Echo(yytext); return(MULOP); }
"&"            { Echo(yytext); return(ANDOP); }
"<"            { Echo(yytext); return(RELOP); }
"=>"           { Echo(yytext); return(ARROW); }
begin          { Echo(yytext); return(BEGIN_); }
case           { Echo(yytext); return(CASE); }
character      { Echo(yytext); return(CHARACTER); }
end            { Echo(yytext); return(END); }
endswitch      { Echo(yytext); return(ENDSWITCH); }
function       { Echo(yytext); return(FUNCTION); }
integer        { Echo(yytext); return(INTEGER); }
is             { Echo(yytext); return(IS); }
list           { Echo(yytext); return(LIST); }
of             { Echo(yytext); return(OF); }
others         { Echo(yytext); return(OTHERS); }
returns        { Echo(yytext); return(RETURNS); }
switch         { Echo(yytext); return(SWITCH); }
when           { Echo(yytext); return(WHEN); }

"-"            { Echo(yytext); return(ADDOP); }
"/"            { Echo(yytext); return(MULOP); }
"%"            { Echo(yytext); return(MODOP); }
"^"            { Echo(yytext); return(EXPOP); }
"~"            { Echo(yytext); return(NEGOP); }
"|"            { Echo(yytext); return(OROP); }
"!"            { Echo(yytext); return(NOTOP); }
{eqop}         { Echo(yytext); return(RELOP); }
else           { Echo(yytext); return(ELSE); }
elsif          { Echo(yytext); return(ELSIF); }
endfold        { Echo(yytext); return(ENDFOLD); }
endif          { Echo(yytext); return(ENDIF); }
fold           { Echo(yytext); return(FOLD); }
if             { Echo(yytext); return(IF); }
left           { Echo(yytext); return(LEFT); }
real           { Echo(yytext); return(REAL); }
right          { Echo(yytext); return(RIGHT); }
then           { Echo(yytext); return(THEN); }
{escape}       { Echo(yytext); return(CHAR_LITERAL); }

{id}           { Echo(yytext); yylval.iden = (CharPtr)malloc(yyleng + 1); 
                  strcpy(yylval.iden, yytext); return(IDENTIFIER);}
{dec}          { Echo(yytext); yylval.type = INT_TYPE; return(INT_LITERAL); }
{double}       { Echo(yytext); yylval.type = REAL_TYPE; return(REAL_LITERAL); }
{hexValue}     { Echo(yytext); yylval.type = INT_TYPE; return(INT_LITERAL); }
{char}         { Echo(yytext); yylval.type = CHAR_TYPE; return(CHAR_LITERAL); }
{punc}         { Echo(yytext); return(yytext[0]); }
.              { Echo(yytext); appendError(LEXICAL, yytext); }

%%

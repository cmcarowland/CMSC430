/* 
   Raymond Rowland
   CMSC 430 Compiler Theory and Design
   Project 1 
   6/20/25
*/

/* This file contains flex input file */

%{
#include <cstdio>
#include <string>

using namespace std;

#include "listing.h"
#include "tokens.h"
#include "utils.h"
%}

%option noyywrap

ws        [ \t\r]+
comment   "//".*\n
line_cmt  "--".*\n
line      [\n]
id        [A-Za-z](_{0,2}[A-Za-z0-9])*
digit     [0-9]
hexValue  #{1}[0-9a-fA-F]+
double    [+-]?{digit}*\.{1}{dec}(?:[Ee]?[+-]?{dec})?
dec       {digit}+
escape    '\\[nrftb]'
eqop      (<|=|<>|>|>=|<=)
char      '.'
punc      [\(\),:;]

%%

{ws}         { Echo(yytext); }
{comment}    { Echo(yytext); nextLine(); }
{line_cmt}   { Echo(yytext); nextLine(); }
{line}       { Echo(yytext); nextLine(); }
"+"          { Echo(yytext); return(ADDOP); }
"-"          { Echo(yytext); return(ADDOP); }
"*"          { Echo(yytext); return(MULOP); }
"/"          { Echo(yytext); return(MULOP); }
"%"          { Echo(yytext); return(REMOP); }
"^"          { Echo(yytext); return(EXPOP); }
"~"          { Echo(yytext); return(NEGOP); }
"&"          { Echo(yytext); return(ANDOP); }
{eqop}       { Echo(yytext); return(RELOP); }
"=>"         { Echo(yytext); return(ARROW); }
"|"          { Echo(yytext); return(OROP); }
"!"          { Echo(yytext); return(NOTOP); }
begin        { Echo(yytext); return(BEGIN_); }
case         { Echo(yytext); return(CASE); }
character    { Echo(yytext); return(CHARACTER); }
end          { Echo(yytext); return(END); }
endswitch    { Echo(yytext); return(ENDSWITCH); }
function     { Echo(yytext); return(FUNCTION); }
integer      { Echo(yytext); return(INTEGER); }
is           { Echo(yytext); return(IS); }
list         { Echo(yytext); return(LIST); }
of           { Echo(yytext); return(OF); }
others       { Echo(yytext); return(OTHERS); }
returns      { Echo(yytext); return(RETURNS); }
switch       { Echo(yytext); return(SWITCH); }
when         { Echo(yytext); return(WHEN); }

else         { Echo(yytext); return(ELSE); }
elsif        { Echo(yytext); return(ELSIF); }
endfold      { Echo(yytext); return(ENDFOLD); }
endif        { Echo(yytext); return(ENDIF); }
fold         { Echo(yytext); return(FOLD); }
if           { Echo(yytext); return(IF); }
left         { Echo(yytext); return(LEFT); }
real         { Echo(yytext); return(REAL); }
right        { Echo(yytext); return(RIGHT); }
then         { Echo(yytext); return(THEN); }
{escape}     { Echo(yytext); return(CHAR_LITERAL); }

{id}         { Echo(yytext); return(IDENTIFIER); }
{dec}        { Echo(yytext); return(INT_LITERAL); }
{double}     { Echo(yytext); return(REAL_LITERAL); }
{hexValue}   { Echo(yytext); return(INT_LITERAL); }
{char}       { Echo(yytext); return(CHAR_LITERAL); }
{punc}       { Echo(yytext); return(yytext[0]); }
.            { Echo(yytext); appendError(LEXICAL, yytext); }

%%

double parse()
{
	firstLine();
	
	FILE *file = fopen("lexemes.txt", "wa"); 
	int token = yylex();
	while (token) {
		fprintf(file, "%d %s\n", token, yytext);
		token = yylex();
	}
	fclose(file);
	
	return lastLine();
}

#ifndef TESTING
int main() {
	parse();
}
#endif
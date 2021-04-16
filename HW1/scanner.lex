%{
#include "tokens.hpp"
%}

%option yylineno
%option noyywrap
WS ([ \t\r\n])
LETTER ([a-zA-Z])
DIGIT ([0-9])
RELATIONOP ((==)|(!=)|<|>|(<=)|(>=))
BINARYOP ([\+|\-|\*|/])
ID {LETTER}({LETTER}|{DIGIT})*
STRINGCHAR ([ -!|#-~])
COMMENTCHAR ([ -~|\t])
STRING (\"({STRINGCHAR}|(\\\"))*\") 
%%

void {return VOID;}
int {return INT;}
byte {return BYTE;}
b {return B;}
bool {return BOOL;}
and {return AND;}
or {return OR;}
not {return NOT;}
true {return TRUE;}
false {return FALSE;}
return {return RETURN;}
if {return IF;}
else {return ELSE;}
while {return WHILE;}
break {return BREAK;}
continue {return CONTINUE;}
switch {return SWITCH;}
case {return CASE;}
default {return DEFAULT;}
: {return COLON;}
; {return SC;}
, {return COMMA;}
\( {return LPAREN;}
\) {return RPAREN;}
\{ {return LBRACE;}
\} {return RBRACE;}
= {return ASSIGN;}
{RELATIONOP} {return RELOP;}
{BINARYOP} {return BINOP;}
\/\/{COMMENTCHAR}* {return COMMENT;}
(0|[1-9]{DIGIT}*) {return NUM;}
{ID} {return ID;}
{STRING} {return STRING;}
{WS} { /* ignore */ }
. {return -1; /* error */ }

%%




%{
#include <maths.h>
#include "tokens.hpp"
int line_number = 1;
%}

WS ([ \t\r])
LETTER ([a-zA-Z])
DIGIT ([0-9])
ID {LETTER} ({LETTER}|{DIGIT})*

%%

{void} {return VOID}
{int} {return INT}
{byte} {return BYTE}
{b} {return B}
{bool} {return BOOL}
{and} {return AND}
{or} {return OR}
{not} {return NOT}
{true} {return TRUE}
{false} {return FALSE}
{return} {return RETURN}
{if} {return IF}
{else} {return ELSE}
{while} {return WHILE}
{break} {return BREAK}
{continue} {return CONTINUE}
{switch} {return SWITCH}
{case} {return CASE}
{default} {return DEFAULT}
{:} {return COLON}
{;} {return SC}
{,} {return COMMA}
{(} {return LPAREN}
{)} {return RPAREN}
{{} {return LBRACE}
{}} {return RBRACE}
{=} {return ASSIGN}
{ == | != | < | > | <= | >= } {return RELOP}
{ + | - | * | / } {return BINOP}
{//.*} {return COMMENT}
{digit+} {return NUM}
{ID} {return ID}
{WS} {/*ignore*/}
\n {line_number++ /*might be irrelevant*/}
. {return -1 /*error*/}
%%




%{
#include "lex.h"
%}

WHITESPACE [ \t]
LF         \n
WORD       [^ \t\n]+

%%
{WHITESPACE} ;
{LF}         ;
{WORD}       return TOKEN_WORD;
%%

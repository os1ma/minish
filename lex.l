%{
#include "lex.h"
%}

WHITESPACE [ \t]
LF         \n
WORD       [^ \t\n]+

%%
{WHITESPACE} ;
{LF}         return TOKEN_LF;
{WORD}       return TOKEN_WORD;
%%

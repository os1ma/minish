%{
  #define WORD 1
%}

WHITESPACE [ \t]
LF         \n
WORD       [^ \t\n]+

%%
{WHITESPACE} ;
{LF}         ;
{WORD}       return WORD;
%%

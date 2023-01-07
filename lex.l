WHITESPACE [ \t]
WORD       [^ \t]+

%%
{WHITESPACE}
{WORD}       { printf("%s\n", yytext); }
%%

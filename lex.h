#pragma once

enum TokenType
{
  TOKEN_LF = 1,
  TOKEN_WORD,
};

extern int yylex(void);
extern char *yytext;

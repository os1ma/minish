#pragma once

typedef enum
{
  TOKEN_LF = 1,
  TOKEN_WORD,
} TokenType;

extern int yylex(void);
extern char *yytext;
extern int yyleng;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

extern int yylex(void);
extern char *yytext;

char *next_token(void)
{
  if (yylex() == 0)
  {
    fprintf(stderr, "yylex failed");
    exit(1);
  }

  return yytext;
}

int main()
{
  while (true)
  {
    printf("> ");

    char *command = next_token();

    if (!strcmp(command, "echo"))
    {
      printf("%s\n", next_token());
    }
    else
    {
      fprintf(stdout, "%s: command not found\n", command);
    }
  }

  return 0;
}

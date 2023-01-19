#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "lex.h"
#include "builtin.h"

#define MAX_ARG 10

TokenType next_token(void)
{
  TokenType type = yylex();

  if (type == 0)
  {
    fprintf(stderr, "yylex failed");
    exit(1);
  }

  return type;
}

int cmd_argc;
char *cmd_argv[MAX_ARG];

int main(void)
{
  while (true)
  {
    printf("> ");

    cmd_argc = 0;
    while (next_token() != TOKEN_LF)
    {
      cmd_argv[cmd_argc] = strdup(yytext);
      cmd_argc++;
    }

    if (cmd_argc == 0)
    {
      continue;
    }

    char *command = cmd_argv[0];

    if (is_builtin(command))
    {
      run_builtin(cmd_argc, cmd_argv);
    }
    else
    {
      fprintf(stdout, "%s: command not found\n", command);
    }
  }

  return 0;
}

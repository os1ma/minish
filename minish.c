#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "lex.h"
#include "builtin.h"
#include "external.h"

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

    // clear args
    for (; cmd_argc != 0; cmd_argc--)
    {
      free(cmd_argv[cmd_argc]);
      cmd_argv[cmd_argc] = NULL;
    }

    // scan args
    while (next_token() != TOKEN_LF)
    {
      if ((cmd_argv[cmd_argc] = strdup(yytext)) == NULL)
      {
        perror("strdup error");
        exit(1);
      }

      cmd_argc++;
    }

    // no command
    if (cmd_argc == 0)
    {
      continue;
    }

    // run command
    char *command = cmd_argv[0];

    if (is_builtin(command))
    {
      run_builtin(cmd_argc, cmd_argv);
    }
    else if (is_external(command))
    {
      run_external(cmd_argc, cmd_argv);
    }
    else
    {
      fprintf(stdout, "%s: command not found\n", command);
    }
  }

  return 0;
}

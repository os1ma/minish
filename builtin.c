#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

static int builtin_exit(int argc, char *argv[]);
static int builtin_echo(int argc, char *argv[]);
static int builtin_true(int argc, char *argv[]);
static int builtin_false(int argc, char *argv[]);

typedef struct
{
  char *name;
  int (*func)(int argc, char *argv[]);
} BuiltinCommand;

static BuiltinCommand commands[] = {
    {"exit", builtin_exit},
    {"echo", builtin_echo},
    {"true", builtin_true},
    {"false", builtin_false},
};

bool is_builtin(char *command)
{
  for (size_t i = 0; i < sizeof(commands) / sizeof(commands[0]); i++)
  {
    if (!strcmp(command, commands[i].name))
    {
      return true;
    }
  }

  return false;
}

int run_builtin(int argc, char *argv[])
{
  for (size_t i = 0; i < sizeof(commands) / sizeof(commands[0]); i++)
  {
    if (!strcmp(argv[0], commands[i].name))
    {
      return commands[i].func(argc, argv);
    }
  }

  fprintf(stderr, "%s: builtin command not found\n", argv[0]);
  exit(1);
}

static int builtin_exit(
    __attribute__((unused)) int argc,
    __attribute__((unused)) char *argv[])

{
  exit(0);
}

static int builtin_echo(int argc, char *argv[])
{
  for (int i = 1; i < argc; i++)
  {
    printf("%s", argv[i]);
    printf(" ");
  }
  printf("\n");

  return 0;
}

static int builtin_true(
    __attribute__((unused)) int argc,
    __attribute__((unused)) char *argv[])
{
  return 0;
}

static int builtin_false(
    __attribute__((unused)) int argc,
    __attribute__((unused)) char *argv[])
{
  return 1;
}

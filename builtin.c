#include <stdio.h>

int builtin_echo(int argc, char *argv[])
{
  for (int i = 1; i < argc; i++)
  {
    printf("%s", argv[i]);
    printf(" ");
  }
  printf("\n");

  return 0;
}

int builtin_true(
    __attribute__((unused)) int argc,
    __attribute__((unused)) char *argv[])
{
  return 0;
}

int builtin_false(
    __attribute__((unused)) int argc,
    __attribute__((unused)) char *argv[])
{
  return 1;
}

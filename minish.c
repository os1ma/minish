#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const ssize_t BUF_SIZE = 4096;

int command_len(char *buf)
{
  for (int i = 0; i < sizeof(buf); i++)
  {
    char c = buf[i];
    if (c == ' ' || c == '\0' || c == '\n')
    {
      return i - 1;
    }
  }

  return -1;
}

int main()
{
  char buf[BUF_SIZE];

  while (1)
  {
    printf("> ");

    fgets(buf, sizeof(buf), stdin);

    int len = command_len(buf);

    char *command = (char *)malloc(sizeof(char) * (len + 1));
    strncpy(command, buf, len + 1);
    command[len + 1] = '\0';

    if (!strcmp(command, "echo"))
    {
      printf("%s", buf + len + 1);
    }
    else
    {
      fprintf(stdout, "%s: command not found\n", command);
    }

    free(command);
  }

  return 0;
}

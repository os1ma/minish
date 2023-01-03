#include <stdio.h>
#include <string.h>

const ssize_t BUF_SIZE = 4096;

int main()
{
  char buf[BUF_SIZE];

  while (1)
  {
    printf("> ");

    fgets(buf, sizeof(buf), stdin);

    if (!strncmp(buf, "echo ", 5))
    {
      printf("%s", buf + 5);
    }
  }

  return 0;
}

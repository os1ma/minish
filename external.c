#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#include "external.h"

static char *path = "/bin/";

static char *to_full_path(char *command)
{
  char *full_path = strdup(path);

  full_path = (char *)realloc(
      full_path,
      sizeof(char) * (strlen(path) + strlen(command) + 1));

  return strcat(full_path, command);
}

static bool exist_file(char *filename)
{
  struct stat buffer;
  return stat(filename, &buffer) == 0;
}

bool is_external(char *command)
{
  char *full_path = to_full_path(command);

  bool res = exist_file(full_path);

  free(full_path);

  return res;
}

int run_external(int argc, char *argv[])
{
  char *full_path = to_full_path(argv[0]);

  pid_t pid = fork();

  if (pid < 0)
  {
    perror("fork failed");
    exit(1);
  }
  else if (pid == 0)
  {
    // setup child process arguments
    char **exec_argv;
    exec_argv = (char **)calloc(sizeof(char *), argc + 1);
    exec_argv[0] = full_path;
    for (int i = 1; i < argc; i++)
    {
      exec_argv[i] = argv[i];
    }
    exec_argv[argc + 1] = NULL;

    execve(full_path, exec_argv, NULL);

    // Do not reach. exit suppress compiler warning
    exit(1);
  }
  else
  {
    // wait child process
    int status;
    wait(&status);
    free(full_path);
    return status;
  }
}

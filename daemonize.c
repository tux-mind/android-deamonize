#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("Usage: %s command [args...]\n\nStart a command and detach from it\n", argv[0]);
    return 0;
  }

  if (daemon(1,1)) {
    fprintf(stderr, "Unable to deamonize: %s\n", strerror(errno));
    return 1;
  }

  execvp(argv[1], &argv[1]);
  fprintf(stderr, "Unable to execute command: %s\n", strerror(errno));
  return 1;
}

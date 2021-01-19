#include "apue.h"
#include <fcntl.h>

int main(int argc, char *argv[]) {
  char *filename;

  if (argc != 2)
    err_quit("usage: a.out <pathname>");
  filename = argv[1];
  if (access(filename, R_OK) < 0)
    err_ret("access error for %s", filename);
  else
    printf("read access OK\n");

  if (open(filename, O_RDONLY) < 0)
    err_ret("open error for %s", filename);
  else
    printf("open for reading OK\n");
  exit(0);
}

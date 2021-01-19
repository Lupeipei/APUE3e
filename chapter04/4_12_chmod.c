#include "apue.h"

int main(void) {
  struct stat statbuf;

  if (stat("bar", &statbuf) < 0)
    err_sys("stat error for bar");

  if(chmod("bar", (statbuf.st_mode & ~S_IXGRP) | S_ISGID) < 0)
    err_sys("chmod error for bar");

  if (chmod("baz", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0)
    err_sys("chmod error for baz");

  exit(0);
}

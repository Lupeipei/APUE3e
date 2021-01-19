#include "apue.h"

int main(void) {
  char *ptr;
  size_t size;

  // /usr/spool/uucppublic is the one place in every system to which UUCP by default is able to copy files.
  // in Macos , using /private/var/spool/uucp
  if (chdir("/private/var/spool/uucp") < 0)
    err_sys("chdir failed");

  ptr = path_alloc(&size);
  if (getcwd(ptr, size) == NULL)
    err_sys("getcwd failed");

  printf("cwd = %s\n", ptr);
  exit(0);
}

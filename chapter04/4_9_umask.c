#include "apue.h"
#include <fcntl.h>

#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

int main(int argc, char *argv[]) {
  if (creat("foo", RWRWRW) < 0)
    err_sys("creat error for foo");
   umask(0);
   if (creat("bar", RWRWRW) < 0)
     err_sys("creat error for bar");
   umask(S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
   if (creat("baz", RWRWRW) < 0)
     err_sys("creat error for baz");
  exit(0);
}

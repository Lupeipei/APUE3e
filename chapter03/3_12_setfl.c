#include "apue.h"
#include <fcntl.h>

int main(int argc, char *argv[]) {
  int fd;

  if (argc != 2)
    err_quit("usage: a.out <descriptor#>");

  fd = atoi(argv[1]);
  set_fl(fd, O_SYNC);
  printf("after setting, fcntl F_GETFL result is %d\n", fcntl(fd, F_GETFL, 0));
  exit(0);
}

void set_fl(int fd, int flags) {
  int val;
  if ((val = fcntl(fd, F_GETFL, 0)) < 0)
    err_sys("fcntl F_GETFL error");

  printf("before setting, fcntl F_GETFL result is %d\n", val);
  val |= flags;

  if (fcntl(fd, F_SETFL, val) < 0)
    err_sys("fcntl F_SETFL error");
}

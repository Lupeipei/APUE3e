#include "apue.h"
#include <fcntl.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(void) {
  int fd;
  int fdno;
  int i = 0;

  if ((fd = creat("file.hole", FILE_MODE)) < 0)
    err_sys("creat error");
  if ((fdno = creat("file.nohole", FILE_MODE)) < 0)
    err_sys("creat error");

  if (write(fd, buf1, 10) != 10)
    err_sys("buf1 write error");
  if (write(fdno, buf1, 10) != 10)
    err_sys("buf1 write error");

  while (i < 16374) {
    if (write(fdno, "0", 1) != 1)
      err_sys("buf3 write error");
    i ++;
  }

  if (lseek(fd, 16384, SEEK_SET) == -1)
    err_sys("lseek error");

  if (write(fd, buf2, 10) != 10)
    err_sys("buf2 write error");
  if (write(fdno, buf2, 10) != 10)
    err_sys("buf2 write error");

  exit(0);
}

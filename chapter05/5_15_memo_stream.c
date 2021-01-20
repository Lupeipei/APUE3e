#include "apue.h"

#define BSZ 48

int main() {
  FILE *fp;
  char buf[BSZ];

  memset(buf, 'a', BSZ - 2);
  buf[BSZ - 2] = '\0';
  buf[BSZ - 1] = 'X';

  printf("initial buffer contents: %s\n", buf);
  printf("len of string in buf after memset a = %ld\n", (long)strlen(buf));

  if ((fp = fmemopen(buf, BSZ, "w+")) == NULL)
    err_sys("fmemopen failed");
  printf("initial buffer contents: %s\n", buf);
  printf("len of string in buf = %ld\n", (long)strlen(buf));
  fprintf(fp, "hello world");
  printf("len of string in buf after fprintf = %ld\n", (long)strlen(buf));
  printf("before flush: %s\n", buf);
  fflush(fp);
  printf("after flush: %s\n", buf);
  printf("len of string in buf = %ld\n", (long)strlen(buf));

  memset(buf, 'b', BSZ - 2);
  buf[BSZ - 2] = '\0';
  buf[BSZ - 1] = 'X';

  printf("initial buffer contents: %s\n", buf);
  printf("len of string in buf after memset b = %ld\n", (long)strlen(buf));
  fprintf(fp, "hello world");
  printf("len of string in buf after fprintf = %ld\n", (long)strlen(buf));
  printf("before fseek: %s\n", buf);
  fseek(fp, 0, SEEK_SET);
  printf("after fseek: %s\n", buf);
  printf("len of string in buf = %ld\n", (long)strlen(buf));

  memset(buf, 'c', BSZ - 2);
  buf[BSZ - 2] = '\0';
  buf[BSZ - 1] = 'X';

  printf("initial buffer contents: %s\n", buf);
  printf("len of string in buf after memset c = %ld\n", (long)strlen(buf));
  fprintf(fp, "hello world");
  printf("len of string in buf after fprintf = %ld\n", (long)strlen(buf));
  printf("before fclose: %s\n", buf);
  fclose(fp);
  printf("after fclose: %s\n", buf);
  printf("len of string in buf = %ld\n", (long)strlen(buf));
  exit(0);
}

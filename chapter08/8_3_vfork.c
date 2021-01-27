#include "apue.h"

int globvar = 6;

int main(void) {
  int   var;
  pid_t pid;

  var = 88;
  printf("before vfork, pid = %ld \n", (long)getpid()); 

  if ((pid = vfork()) < 0) {
    err_sys("vfork error");
  } else if (pid == 0) {
    globvar++;
    var++;
    _exit(0);
  }
  printf("pid = %ld, globvar = %d, var = %d\n", (long)getpid(), globvar, var);
  exit(0);
}

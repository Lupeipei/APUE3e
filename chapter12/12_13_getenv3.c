#include <string.h>
#include <errno.h>
#include <pthread.h>
#include <stdlib.h>

#define MAXSTRINGSZ 4096
static pthread_key_t key;
static pthread_once_t init_done = PTHREAD_ONCE_INIT;
pthread_mutex_t env_mutex = PTHREAD_MUTEX_INITIALIZER;
extern char **environ;

static void thread_init(void) {
  pthread_key_create(&key, free);
}

char * getenv(const char *name) {
  int i, len;
  char *envbuf;

  /* 多个线程同时调用 getenv_r时, pthread_once 只会调用一次, 创建的key, 每个线程访问时, 获取各自特定的数据地址 */
  pthread_once(&init_done, thread_init);
  pthread_mutex_lock(&env_mutex);
  envbuf = (char *)pthread_getspecific(key);
  if (envbuf == NULL) {
    envbuf = malloc(MAXSTRINGSZ);
    if (envbuf == NULL) {
      pthread_mutex_unlock(&env_mutex);
      return(NULL);
    }
    pthread_key_setspecific(key, envbuf);
  }
  len = strlen(name);
  for (i = 0; environ[i] != NULL; i++) {
    if ((strncmp(name, environ[i], len) == 0) && (environ[i][len] == '=')) {
      strncpy(envbuf, &environ[i][len+1], MAXSTRINGSZ-1);
      pthread_mutex_unlock(&env_mutex);
      return(envbuf);
    }
  }
  pthread_mutex_unlock(&env_mutex);
  return(NULL);
}

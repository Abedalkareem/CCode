//
//  threads.c
//  CCode
//
//  Created by abedalkareem omreyh on 05/12/2022.
//

#include "threads.h"
#include <pthread.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

void* hello(void *ptr) {
  pthread_detach(pthread_self());
  printf("%s\n", (char *)ptr);
  pthread_t thread = pthread_self();
  printf("In function thread id = %lu\n", (long) thread);
  char * usr = malloc(25);
  sleep(1);
//  pthread_cancel(pthread_self());
  strcpy(usr,"hello world\n");
  pthread_exit(usr);
}

void testThreads(void) {
  pthread_t thread;
  pthread_create(&thread, NULL, hello, (void*) "hello?");
  char* returned = NULL;
  pthread_join(thread, (void**)&returned); // Wait for the thread to finish.
  printf("result? %s\n", returned);
  printf("Hello hahahaha \n");
  pthread_exit(NULL);
}


pthread_mutex_t *lock = NULL;

void* doProcess(void *ptr) {
  pthread_mutex_lock(lock);
  // do somework
  sleep(3);
  pthread_mutex_unlock(lock);

  pthread_exit(NULL);
}

void lockMain(void) {
  pthread_t t1, t2;

  pthread_mutex_init(lock, NULL);

  pthread_create(&t1, NULL, doProcess, NULL);
  pthread_create(&t2, NULL, doProcess, NULL);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

}


pthread_mutex_t lock2 = PTHREAD_MUTEX_INITIALIZER;

void* doProcess2(void *ptr) {
  pthread_mutex_lock(&lock2);
  // do somework
  sleep(3);
  pthread_mutex_unlock(&lock2);

  pthread_exit(NULL);
}

void lockMain2(void) {
  pthread_t t1, t2;

  pthread_create(&t1, NULL, doProcess, NULL);
  pthread_create(&t2, NULL, doProcess, NULL);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

}

// while (pthread_mutex_trylock(&lock2))

pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t condition_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition_cond = PTHREAD_COND_INITIALIZER;

int cound = 0;



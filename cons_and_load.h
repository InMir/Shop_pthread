#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#ifndef _CONS_AND_LOADER_H_
#define _CONS_AND_LOADER_H_

pthread_mutex_t mutex_loader;
typedef struct someArgs_tag {
	int shop[5];
	int user[3];
	int gflag;
	int flag[3];
	int number_user;
} someArgs_t;

void* consumer(void * );
void* loader(void * );

#endif

#include "cons_and_load.h"

void* loader(void *args)
{
	someArgs_t *arg = (someArgs_t*) args;
	srand( time( 0 )); 
	int tmp;
	int rand_shop = rand()%4;
	pthread_mutex_lock(&mutex_loader);
	tmp = arg -> shop[rand_shop];
	tmp = tmp + 100;
	arg -> shop[rand_shop] = tmp;
	printf("Loader... \n");
	pthread_mutex_unlock(&mutex_loader);
}

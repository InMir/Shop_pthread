#include "cons_and_load.h"

void* consumer(void *args)
{
	someArgs_t *arg = (someArgs_t*) args;
	srand( time( 0 )); 
	int tmp, tmp1, number_user;
	int rand_shop = rand()%4;
	
	pthread_mutex_lock(&mutex_loader);
	number_user = arg -> number_user; 
	tmp = arg -> shop[rand_shop];
	tmp1 = arg -> user[number_user];
		
	tmp1 = tmp1 - tmp;
	
	if(tmp1 < 0){
		tmp = (-1)*tmp;
		arg -> flag[number_user] = 1;
		(arg -> gflag)++;		
	}
	else
	if (tmp1 == 0){
		tmp = 0;
		arg -> flag[number_user] = 1;
		(arg -> gflag)++;	
	}
	else
		tmp = 0;
	arg -> shop[rand_shop] = tmp;
	arg -> user[number_user] = tmp1;
	printf("Consumer %d... \n", number_user + 1);
	pthread_mutex_unlock(&mutex_loader);
}

#include "cons_and_load.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// gcc -Wall -o Shop Shop.c -pthread -std=c99

int main(void)
{
	srand( time( 0 )); 
	someArgs_t project;
	for(int i = 0; i < 5; i++){
		project.shop[i] = 90 + rand()%10;		
	}
	for(int i = 0; i < 3; i++){
		project.user[i] = 900 + rand()%100;		
	}	
	project.gflag = 0;
	for(int i = 0; i < 3; i++){
		project.flag[i] = 0;		
	}		
	project.number_user = 0;	
	pthread_t tid;
	pthread_mutex_init(&mutex_loader, NULL);
	while(1)
	{
		printf(" Goods in stores %d %d %d %d %d \n", 
		project.shop[0] , project.shop[1] , project.shop[2] , project.shop[3] , project.shop[4] );
		printf(" Consumer needs %d %d %d\n", 
		project.user[0], project.user[1] , project.user[2]);	
		pthread_create(&tid, NULL, loader,(void*) &project);
		sleep(2);
		if(project.flag[0] == 0){
			project.number_user = 0;
			pthread_create(&tid, NULL, consumer,(void*) &project);
			sleep(3);			
		}	
		if(project.flag[1] == 0){
			project.number_user = 1;			
			pthread_create(&tid, NULL, consumer,(void*) &project);
			sleep(3);			
		}	
		if(project.flag[2] == 0){
			project.number_user = 2;			
			pthread_create(&tid, NULL, consumer,(void*) &project);
			sleep(3);			
		}	
		if(project.gflag == 3){
			pthread_mutex_destroy(&mutex_loader);
			return 0;	
		}			
	}
}

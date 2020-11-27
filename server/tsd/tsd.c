#include "tsd.h"
#include <pthread.h>

void destr(void *arg){
	printf("destroy memory, pthread_self is %ld\n\n",pthread_self());
	free(arg);
}

void thread_init(){
	pthread_key_create(&Key,destr);
}
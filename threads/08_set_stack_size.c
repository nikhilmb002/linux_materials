#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define CUSTOM_STACK_SIZE (250L*1024*1024*1024)

void* thread_fun(void* p) {

	while(1);
}

int main() {

	pthread_t thread;
	pthread_attr_t attr;
	size_t stack_size;
	pthread_attr_init(&attr);
	pthread_attr_setstacksize(&attr, CUSTOM_STACK_SIZE);
	pthread_attr_getstacksize(&attr, &stack_size);
	stack_size = (double)stack_size / (1024 * 1024);	
	printf("Thread stack size : %ld MB\n", stack_size);
	pthread_create(&thread, &attr, thread_fun, 0);
	pthread_join(thread, 0);
	pthread_attr_destroy(&attr);
	while(1);	
}

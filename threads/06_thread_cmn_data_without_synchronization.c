// common data access between threads without using synchronization method

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int g = 0;

void* thread1 (void* p) {

	printf("in thread1 g val : %d\n", g);
	g++;
	printf("thread1 updated g val for internal use ...\n");
	sleep(5);
	printf("in thread1 g val : %d\n", g);
	printf("thread1 code executing ...\n");
	sleep(2);
	printf("thread1 terminated...\n");	
}

void* thread2 (void* p) {

	sleep(1);
	printf("in thread2 g val : %d\n", g);
	g = 10;
	printf("thread2 updated g val as 10\n");
	sleep(1);
	printf("thread2 executing...\n");
	sleep(2);
	printf("thread2 terminated...\n");
}

int main() {

	pthread_t t1, t2;
	pthread_create(&t1, 0, thread1, 0);
	pthread_create(&t2, 0, thread2, 0);
	while(1);
}

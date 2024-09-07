#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int g = 0;

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

void* thread1(void* p) {

	pthread_mutex_lock(&m);
	printf("in thread1 g : %d\n", g);
	sleep(2);
	printf("Unlocking thread1..\n");
	pthread_mutex_unlock(&m);
	sleep(2);
	pthread_mutex_lock(&m);
	g = 10;
	printf("in thread1 g : %d\n", g);		
	pthread_mutex_unlock(&m);
}

void* thread2(void* p) {
	
	sleep(3);
	pthread_mutex_lock(&m);
	g = 100;
	printf("in thread2 g val : %d\n", g);
	sleep(5);
	printf("thread2 unlocking ...\n");
	pthread_mutex_unlock(&m);
}

int main() {
	
	pthread_mutexattr_t attr;
	pthread_mutexattr_init(&attr);
	pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
	pthread_mutex_init(&m, &attr);
	pthread_t t1, t2;
	pthread_create(&t1, 0, thread1, 0);
	pthread_create(&t2, 0, thread2, 0);
	while(1);
}

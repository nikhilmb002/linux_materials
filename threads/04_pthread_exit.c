/* waiting for specific thread termination, pthread_exit */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thread1() {

	printf("Thread1 code started ...\n");
	sleep(5);
	pthread_exit("Thread1 exit");
}

void* thread2() {

	printf("Thread2 code started ...\n");
	sleep(5);
	printf("Thread2 terminated...\n");
}

int main() {
	
	char* p;
	pthread_t t1, t2;
	printf("Main thread code execution ...\n");
	pthread_create(&t1, 0, thread1, 0);
	pthread_create(&t2, 0, thread2, 0);
	printf("Main thread waiting for thread1 termination ...\n");
//	pthread_join(t1, 0); 
	pthread_join(t1, &p);	// waiting for specific thread termination
	printf("after pthread_join %s\n", p);
	printf("main thread going to terminate ...\n");
}

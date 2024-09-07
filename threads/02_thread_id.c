#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thread1(void* p) {

	printf("%s\n", (char*)p);
	printf("Thread1 id : %u\n", pthread_self());
	while(1);
}

void* thread2(void* p) {
	
	printf("%s\n", (char*)p);
	while(1);
}

int main() {

	pthread_t t1, t2;
	pthread_create(&t1, 0, thread1, "Thread1");	// thread1 id stored in t1
	pthread_create(&t2, 0, thread2, "Thread2");	
//	printf("Thread1 id : %u\n", t1);
	printf("Thread2 id : %u\n", t2);
	printf("Main thread code execution ...\n");
	sleep(10);
	printf("main thread(process) finished ...\n");

//	while(1);

}

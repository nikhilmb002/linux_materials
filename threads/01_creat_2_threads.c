#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thread1(void* p) {

	while(1) {

		printf("%s\n", (char*) p);
		sleep(1);
	}
}

void* thread2(void* p) {

	while(1) {

		printf("%s\n", (char*) p);
		sleep(1);
	}
}

int main() {

	pthread_t t1;
	pthread_t t2;
	pthread_create(&t1, 0, thread1, "hello");
	pthread_create(&t2, 0, thread2, "hai");

	while(1) {

		printf("Main...\n");
		sleep(1);
	}

	return 0;
}

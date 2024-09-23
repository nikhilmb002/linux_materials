#include <stdio.h>
#include <unistd.h>
int main() {

	printf("hello process ...\n");
	sleep(3); // it provides the delay of 3 seconds (process entring to delay state)
	printf("process termination...\n");
}

// admitted -> ready -> running -> delay -> ready -> running -> termination 

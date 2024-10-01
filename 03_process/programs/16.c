#include <stdio.h>
#include <unistd.h>
int main() {

	if(fork() == 0) {

		printf("child pid : %d\n", getpid());
		printf("child ppid : %d\n", getppid());
		sleep(5);
		printf("child pid : %d\n", getpid());	// orphan process 
		printf("child ppid : %d\n", getppid());
		printf("child exit\n");
	}
	
	else {

		sleep(2);
		printf("parent pid : %d\n", getpid());
		printf("parent ppid : %d\n", getppid());
		while(1);
	}	
}

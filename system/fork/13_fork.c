// in parent and child process combination always parent process will run as foreground process and child process will run as background process

#include <stdio.h>
#include <unistd.h>
int main() {
	
	if(fork() == 0) {
	
		sleep(5);
		printf("in child process\n");
		printf("child pid : %d\n", getpid());
		printf("child exit\n");
	}

	else {
	
		printf("in parent process\n");
		printf("parent process pid : %d\n", getpid());
		sleep(3);
		printf("parent process exit\n");	
	}
}



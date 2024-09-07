#include <stdio.h>
#include <unistd.h>

int main() {

	if(fork() == 0) {	// exclusively for child
		
		printf("in child process\n");
		printf("child pid  : %d\n", getpid());
		printf("ppid : %d\n", getppid());
	}

	else { // exclusively for parent
		
		printf("in parent process\n");
		printf("parent process pid : %d\n", getpid());
		printf("ppid : %d\n", getppid());	
	}
}

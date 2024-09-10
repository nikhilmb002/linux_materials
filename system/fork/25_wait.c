#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {

	if(fork() == 0) {
	
		printf("in child process pid : %d\n", getpid());
		sleep(10);
		printf("child exit ...\n");
	}

	else {
		
		printf("in parent process ...\n");
		wait(0);	/* when wait system call parent process is blocked until child process termination,if child process terminated internally wait system call collect status and free the resources occupied child process */
		printf("after wait sys call ...\n");
		while(1);
	}

}

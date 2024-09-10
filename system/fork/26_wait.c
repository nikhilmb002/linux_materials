#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main() {

	if(fork() == 0) {
	
		printf("in child process pid : %d\n", getpid());
		sleep(10);
		printf("child exit ...\n");
	//	exit(0);	//0
	//	exit(1);	//256
		exit(2);	//512
	}

	else {
		short int stat;
		printf("in parent process ...\n");
		wait(&stat);
		printf("after wait sys call ...\n");
		printf("stat : %d\n", stat);
		while(1);		
	}
}

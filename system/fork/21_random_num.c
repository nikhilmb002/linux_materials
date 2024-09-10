#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	
	if(fork() == 0) {
	
		int t1;
		srand(getpid());
		t1 = rand()%10+1;	// 1 to 10
		printf("child process goes to delay of %d sec\n", t1);
		sleep(t1);
		printf("child process termination\n");
	}
	
	else {
	
		int t2;
		srand(getpid());
		t2 = rand()%10+1;
		printf("parent process goes to delay of %d sec\n", t2);
		sleep(t2);
		printf("parent process terminated\n");
	}

	return 0;
}

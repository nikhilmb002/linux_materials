#include <stdio.h>
#include <unistd.h>
int main() {

	if (fork() == 0) {

		sleep(4);
		printf("child pid : %d\n", getpid());
		printf("child exit\n");
	}

	else {
		
		printf("ppid : %d\n", getpid());
		sleep(1);
		printf("parent process exit...\n");
	}
}

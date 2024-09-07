#include <stdio.h>
#include <unistd.h>

int  main() {
	
	if(fork() == 0) {
	
		printf("child pid  : %d\n", getpid());
		printf("child ppid : %d\n", getppid());
		sleep(5);
		printf("child pid  : %d\n", getpid()); 
		printf("child ppid : %d\n", getppid());
		printf("child exit...\n");
	}

	else {
	
		sleep(2);
		printf("parnt pid  : %d\n", getpid());
		printf("parnt ppid : %d\n", getppid());
		while (1);
	}

	return 0;
}

/* In parent and child process relation if child process terminated first but parent process not terminated then child becomes zombie process. 
 
   A dead process but resources are not released...
	

   Many zombie process creation leads to problem because zombie process resources are not released, hence there is a chance of resource shortage...
*/

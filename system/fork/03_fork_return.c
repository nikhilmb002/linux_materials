/* return value of fork , on success PID of the child process is returned in parent, and 0 is returned in child... On failure -1 is returned in parent, no child process is created.... */

#include <stdio.h>
#include <unistd.h>

int main() {
	
	int ret;
	printf("Hello...\n");
	ret = fork();	//3
	printf("ret : %d\n", ret);
	return 0;
}

/*
	due to //3 
       
	main() {
	
		-----------
		-----------
		-----------
		printf("ret : %d\n", ret);
		return 0;	
	}

	to parent process child pid is return values
	to child process returns 0 
*/



#include <stdio.h>
#include <unistd.h>

int main() {

	int ret;
	printf("Hi\n");
//	ret = fork();
	
//	if (ret == 0) {

	if (fork() == 0) {

		printf("child pid : %d ppid : %d\n", getpid(), getppid());
		while(1);
	}

	else {
		
		printf("parent  pid : %d ppid : %d\n", getpid(), getppid());
		while(1);
	}
}

/* 
	~$ ps -e | grep pts/1
   	
		2035 pts/1    00:00:00 bash
   		2679 pts/1    00:00:09 p7
   		2680 pts/1    00:00:09 p7

*/

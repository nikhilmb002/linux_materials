#include <stdio.h>
#include <unistd.h>

int main() {

	int ret;
	printf("hello...\n");
	ret = fork(); // 5

	if(ret == 0) {

		// printf("one\n");
		printf("exclusive child...\n");
		printf("pid : %d ppid : %d\n", getpid(), getppid());
		while(1);

	}

	else {

		// printf("two\n");
		printf("exclusive parent process...\n");
		printf("pid : %d ppid : %d\n", getpid(), getppid());
		while(1);
	}
}

/* Because of //5 new process is created 
 
   	main() {
	
		------
		------
		------

		if(ret == 0) 

			printf("one\n");

		else 

			printf("two\n");	
	}

*/

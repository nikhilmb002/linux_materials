#include <stdio.h>
#include <unistd.h>

int main() {

	int i = 10;
	
	if (fork() == 0) {

		printf("In child i : %d\n", i);
		sleep(6);
		printf("In child i : %d\n", i);
		printf("child exit\n");
	}

	else {

		sleep(2);
		printf("In parent i : %d\n", i);
		printf("In parent i value updated as 20\n");
		i = 20;
		printf("In parent i : %d\n", i);
		sleep(2);
		printf("parent process exit\n");
	}
}

/*
	Once parent or child modify the common data then a seperate page (copy) created for the process. Because of this technic changes made by 1 process will not effect to other process. 
*/

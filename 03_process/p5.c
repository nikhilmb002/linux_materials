#include <stdio.h>
#include <unistd.h>
int main() {

	int ret;
	printf("Hi...\n");
	ret = fork();		//line_3
	printf("ret : %d\n", ret);
}

/* 
	
	because of fork() in line_3 child is created, assuming pid : 2494
	
	child : pid 2494
	
	main() {

		.....
		printf("ret : %d\n", ret);
	}

*/

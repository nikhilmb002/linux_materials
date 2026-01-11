#include <stdio.h>
#include <unistd.h>

int main() {

	int ret;
	printf("Hi...\n");
	ret = fork();	//line_3
	
	if (ret == 0) {

		printf("Child...\n");
	}

	else {

		printf("Parent...\n");
	}

}

/* 
	
	Because of line_3 child is created 
	

		int main() {
		
			............................

			if (ret == 0) {
	
				printf("Child...\n");
			}

			else {

				printf("Parent...\n");
			}

		}	


		To the parent process the child PID is returned. 

		so the if (ret == 0) false , then parent process executes else part. 

		The child process get retun value of 0, then if part is executed by child process. 

		
*/





















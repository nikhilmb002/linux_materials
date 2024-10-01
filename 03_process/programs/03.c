#include <stdio.h>
#include <unistd.h>

int main() {
	
	printf("Hi...\n");
	fork();
	printf("Bye...\n");
}

/* 
	because of fork() new process is created. The p3 is the parent process. The new process created is child and all thing are duplicated 

		int main() {

	        	printf("Hi...\n");
        		fork();
        		printf("Bye...\n");
		
		}

		// but in child process code after the fork is executed... 

		when child process created everything (code, stack, data, heap) are duplicated from parent process. 

		After child get created it is difficult to predict who (parent or child) will start the exeuction first. It depends upon time slice. 


	So the output : 

		Hi... 
		Bye... 
		Bye...
 

*/ 


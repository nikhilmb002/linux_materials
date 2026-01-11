/* 	
	Create parent and child process of follows 

	  x  -> x+1
	x+1 -> x+2
	x+2 -> x+3
*/


#include <stdio.h>
#include <unistd.h>
int main() {

	if (fork() == 0) {

		printf("pid : %d ppid : %d\n", getpid(), getppid());

		if (fork() == 0) {
			
			printf("pid : %d ppid : %d\n", getpid(), getppid());	
			
			if (fork() == 0) {
		
				printf("pid : %d ppid : %d\n", getpid(), getppid());
				while(1);		
			}	

			while(1);
		}
	
		while(1);
	
	}

	else 

		while(1);
}



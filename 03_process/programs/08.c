/* 	
	Create 3 child process from the same parent 
	Parent pid : x 

 	    [x+1] <-------[x]--------> [x+2]
			   |
			   |
			 [x+3]
*/	

#include <stdio.h>
#include <unistd.h>
int main() {

	if (fork() == 0) {

		printf("pid : %d ppid : %d\n", getpid(), getppid());
	}

	else {

		if (fork() == 0) {

			printf("pid : %d ppid : %d\n", getpid(), getppid());
		}

		else {

			if (fork() == 0) {

				printf("pid : %d ppid : %d\n", getpid(), getppid());
			}

			else {
				
				while(1);
			}

		}

	}

}

/* 

	1. Program starts with one process called the parent process (PID = x).

	2. The first fork() is executed.
   		- Parent creates Child-1.
   		- In Child-1, fork() returns 0, so it enters the if block.
 		- Child-1 prints its PID and parent PID, then exits.
   		- Parent goes to the else block.

	3. Inside the first else block, the second fork() is executed.
 		- Parent creates Child-2.
  		- In Child-2, fork() returns 0, so it prints its PID and parent PID.
   		- Child-2 exits.
  		- Parent continues to the next else block.

	4. Inside the second else block, the third fork() is executed.
		- Parent creates Child-3.
		- In Child-3, fork() returns 0, so it prints its PID and parent PID.
   		- Child-3 exits.
   		- Parent enters the final else block.

	5. The parent process executes while(1) to stay alive.

*/


















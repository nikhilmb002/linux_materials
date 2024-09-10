/* write a program to create 3 child processes from the same parent, use rand and srand functions to generate delay in the range of 1 to 10 seconds in each child, design the parent process in such a way that parent should wait until all child processses termination and also parent should display order of child process termination */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

	int t1, t2, t3;
	int pid[3];

	if((pid[0] = fork()) == 0) {
	
		//child 1

		srand(getpid());
		t1 = rand() % 10 + 1;
		printf("child1 goes to delay of %d sec\n", t1);
		sleep(t1);
		exit(0);
	}	

	else {
	
		if((pid[1] = fork()) == 0) {
			
			//child 2

			srand(getpid());
			t2 = rand() % 10 + 1;
			printf("child2 goes to delay of %d sec\n", t2);
			sleep(t2);
			exit(0);
		}

		else {
		
			if((pid[2] = fork()) == 0) {
			
				// child 3
				
				srand(getpid());
				t3 = rand() % 10 + 1;
				printf("child3 goes to delay of %d sec\n", t3);
				sleep(t3);
				exit(0);
			}		

			else {

				int ret;
				short int stat;
				
				while((ret = wait(&stat)) != -1) {	// if there are no child existing then wait will return -1
					
					if(pid[0] == ret) 
						
						printf("child1 terminated\n");

					else if(pid[1] == ret) 

						printf("child2 terminated\n");

					else if(pid[2] == ret)

						printf("child3 terminated\n");						
				}

				printf("parent process terminated ...\n");
			}
		}
	}
}


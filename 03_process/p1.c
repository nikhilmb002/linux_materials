#include <stdio.h>
#include <unistd.h>
int main() {

	printf("Hi\n");
	printf("pid : %d ppid : %d\n", getpid(), getppid());
	while(1);
}


/* 

	s$ ./p1
	Hi
	pid : 1573 ppid : 1162
	$ ^C
	$ ps
    	
	PID TTY          TIME CMD
	1162 pts/1    00:00:01 bash
   	1574 pts/1    00:00:00 ps



	When a process started execution under a terminal by default bash(shell) act as parent

	Terminal is logical windows under this terminal (when terminal opens) bash started
*/

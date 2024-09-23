/* wap to implement the task 
 
   Parent process writes the data into the pipe, after writing child process will read the data, and converts each letter into opposite case after that again child process writes back into pipe, parent process will read data from pipe and display */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
	
	int fd[2];
	
	if(pipe(fd) < 0) {
	
		perror("pipe");
		return 0;
	}


	// printf("fd[0] : %d fd[1] : %d\n", fd[0], fd[1]); // 3 4
	
	if(fork() == 0) {
	
		int i;
		char buf[50];
		read(fd[0], buf, sizeof(buf));	// when no data availble in pipe read system call got blocked
	
		for(i = 0; buf[i]; i++) 

			buf[i] = buf[i] ^ 32;

		write(fd[1], buf, strlen(buf)+1);
	}

	else {
	
		char buf[50];
		printf("Enter data \n");
		scanf("%s", buf);
		write(fd[1], buf, strlen(buf)+1);	
		sleep(2);
		read(fd[0], buf, sizeof(buf));
		printf("data : %s\n", buf);
	}
}

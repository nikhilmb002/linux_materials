/* wap to find the size of the pipe */

#include <stdio.h>
#include <unistd.h>

int main() {

	int fd[2], count = 0, ret;
	char ch = 'a';

	if(pipe(fd) < 0) {

		perror("pipe");
		return 0;
	}	

	while((ret = write(fd[1], &ch, 1) > 0)) { 

		count++;
		printf("size of the pipe : %d\n", count);
	}
	
	
//	printf("size of the pipe : %d\n", count);	// if pipe is full process got blocked, so it doesn't print

	return 0;
}

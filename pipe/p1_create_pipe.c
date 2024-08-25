/* program to create a pipe */

#include <stdio.h>
#include <unistd.h>

int main() {
	
	int fd[2], ret;

	if(ret = pipe(fd) < 0) {
	
		perror("pipe");
		return 1;
	}

	printf("fd[0] : %d fd[1] : %d\n", fd[0], fd[1]);
}

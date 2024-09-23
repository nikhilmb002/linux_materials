/* method 2 */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {

	int fd[2], ret, count = 0;
	char ch = 'a';

	pipe2(fd, O_NONBLOCK); // because of O_NONBLOCK flag when the pipe is full, instead of process block, write system call fails so that while loop condition false

	printf("fd[0] : %d fd[1] : %d\n", fd[0], fd[1]);

	while((ret = write(fd[1], &ch, 1)) > 0) 
		
		count++;

	printf("ret : %d\n", ret);

	printf("size of pipe : %d\n", count);
	
	return 0;
}

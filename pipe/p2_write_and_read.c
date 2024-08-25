#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {

	int fd[2];
	
	if(fork() == 0) {
	
		char buf[50];
		read(fd[0], buf, sizeof(buf));
		printf("After reading data from pipe : %s\n", buf);
	}

	else {
	
		char buf[50];
		printf("Enter data \n");
		scanf(" %s", buf);
		write(fd[1], buf, strlen(buf)+1);
	}
	
	return 0;
}

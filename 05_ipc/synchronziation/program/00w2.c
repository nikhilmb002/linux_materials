#include "header.h"
int main() {

	char a[] = "ABCDEFGHIJKLMNOPQR";
	int fd;

	fd = open("data", O_RDWR | O_APPEND | O_CREAT, 0644);
	
	if (fd < 0) {
	
		perror("open");
		return 1;
	}

	for (int i = 0; a[i]; i++) {

		write(fd, &a[i], 1);	
		sleep(1);
	}

	printf("Done ...\n");
}

/* 	
	Both programs write to the same file concurrently
	Each write is only one byte long 
	No synchronization (locks, semaphores) is used
	This results in a race condition
	Output in the file is interleaved and non determinstic 
*/

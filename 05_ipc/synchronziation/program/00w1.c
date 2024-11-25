#include "header.h"
int main() {

	char a[] = "abcdefghijklmnopqr";
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
		fd = open("data", O_RDWR | O_APPEND | O_CREAT, 0644);

		opens the file named "data"
		
		O_RDWR   : open file for reading and writing 
		O_APPEND : all writes are appended to the end of the file 
		O_CREAT  : create the file if it does not exist 
		0644 	 : file permissions (rw- r-- r--)

*/ 

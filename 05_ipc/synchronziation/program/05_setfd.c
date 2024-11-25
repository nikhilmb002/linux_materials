#include "header.h"
int main() {

	int fd = open("data", O_CREAT | O_RDWR, 0664);	// Returns a fd usually 3 

	fcntl(fd, F_SETFD, FD_CLOEXEC);	// set FD_CLOEXEC flag (close fd automatically on exec)
	
	int flags = fcntl(fd, F_GETFD);	// now read back fd flags 

	if (flags & FD_CLOEXEC) 

		printf("CLOEXEC ON\n");

	else 

		printf("CLOEXEC OFF\n");

	return 0;
}



















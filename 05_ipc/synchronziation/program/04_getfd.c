#include "header.h"
int main() {

	int fd = open("data", O_CREAT | O_RDWR, 0664);	// Returns a fd usually 3 

	int flags = fcntl(fd, F_GETFD);	

	if (flags & FD_CLOEXEC) 

		printf("CLOEXEC ON\n");

	else 

		printf("CLOEXEC OFF\n");

	return 0;
}

/* 
	
	int flags = fcntl(fd, F_GETFD);
	
		This retrives FD flags associated with fd 

		Currently linux mainly supports 

			FD_CLOEXEC 
	
	Typical Output 

		CLOEXEC OFF

		Because by default 

			FD_CLOEXEC is not set

	What does FD_CLOEXEC Mean ?

		close this file descriptor automatically when exec() is called.

		if set : file is closed during exec()

		if not set : file is inherited by new program 


*/


















#include "header.h"
int main() {

	int fd = fcntl(1, F_DUPFD, 10);
	
	printf("new fd = %d\n", fd);

	return 0;
}

/* 

	Purpose of the program 

	This program : 

		Duplicates STDOUT (fd = 1)
		Requests the new file descriptor number to be at least 10 
		prints the new file descriptor returned by the kernel 

		int fd = fcntl(1, F_DUPFD, 10);

			1 -> STDOUT 
			F_DUPFD -> duplicate file descriptor 
			10 -> minimum fd value

		What kernel does 

			searches for the lowest unused file descriptor >= 10 
			creates a duplicate of fd 1 
			returns that new fd 

			in my run : 

				new fd = 10 

			Meaning : 

				fd 10 was free 
				kernel duplicated STDOUT into fd 10 


			File Descriptor Table After Execution 

				0  → STDIN
				1  → STDOUT
				2  → STDERR
				...
				10 → STDOUT (duplicate)

*/

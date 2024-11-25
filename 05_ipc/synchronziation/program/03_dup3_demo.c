#include "header.h"
int main() {

	int newfd;

	// Duplicate STDOUT (fd 1) into fd 5 and set CLOEXEC 

	newfd = dup3(1, 5, O_CLOEXEC);
	
	if (newfd < 0) {

		perror("dup3");
		return 1;
	}

	printf("new fd = %d\n", newfd);
	
	write (newfd, "Hello via dup3\n", 15);	// write using the new fd 

	return 0;
}


/* 
	
	output : 

		new fd = 5
		Hello via dup3 


	What this program does 

		dup3(1, 5, O_CLOEXEC);

			1 -> STDOUT 
			5 -> exact new fd you want
			O_CLOEXEC -> close fd 5 automatically on exec()

		so 
			FD becomes a duplicate of STDOUT 
			FD 5 will not leak into exec'd programs 

		FD table conceptually 

			0 → STDIN
			1 → STDOUT
			2 → STDERR
			5 → STDOUT (duplicate, CLOEXEC enabled)
			
	
*/


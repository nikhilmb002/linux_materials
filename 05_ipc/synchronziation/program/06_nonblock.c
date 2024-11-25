#include "header.h"
int main() {

	int flags = fcntl(0, F_GETFL);
	
	fcntl(0, F_SETFL, flags | O_NONBLOCK);

	char b[10];
	
	if (read (0, b, 10) < 0) 

		perror ("read");

	return 0;
}

/* 

	Purpose of the program 

		Converts STDIN (keyboard input) into non-blocking mode 
		Tries to read input immediately 
		If no input is available, it print an error instead of waiting 

		
	Step by Step Explanation

		int flags = fcntl(0, F_GETFL);
		
			0 = STDIN
			F_GETFL = get file status flags 

		This reads existing flags like 

			O_RDONLY 
			O_NONBLOCK (if already set)

		Nothing changes yet - just reading current settings 

		
		Enable non blocking mode 

			fcntl(0, F_SETFL, flags | O_NONBLOCK);
		
			Adds O_NONBLOCK to existing flags 

			Makes STDIN non-blocking 

			Meaning 

				read() will not wait for keyboard input 	

				It returns immediately 

		Buffer declaration 

			char b[10];

			buffer to store input data 

		Try to read from STDIN 

			if (read(0, b, 10) < 0)
			    perror("read");

			Tries to read 10 bytes from STDIN 
			Since no input is typed 

				read() fails 
				errno = EAGAIN

		perror() prints 

			read: Resource temporarily unavailable


		This means 

			No input available 
			But program didn't block 
			Returned immediately


*/









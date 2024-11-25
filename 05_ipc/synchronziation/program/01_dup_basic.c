#include "header.h"
int main() {

	int fd = dup(1);	// duplicate stdout 
	
	printf("New fd = %d\n", fd);
	
	write(fd, "Hello\n", 6); // also goes to terminal 
	
	return 0;
}

/* 
	
	Output 

	New fd = 3
	Hello 


	dup() returns lowest free FD 
	Both 1 and 3 point to same ouput 


*/

#include "header.h"
int main() {

	int fd = open("out.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);	
	
	dup2(fd, 1);	// stdout -> file 

	printf("Hello file\n");

	return 0;
}

/* 

	./a.out 
	cat out.txt

	Output 
	
		Hello file 


	Concept 

		stdout -> out.txt 

	This is how 

		echo Hello file > out.txt 

	

*/

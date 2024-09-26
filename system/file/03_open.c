#include <stdio.h>
#include <fcntl.h>

int main() {

	int fd;
//	fd = open("temp", O_WRONLY);	// if file is not there, O_WRONLY willn't create

     // printf("fd : %d\n", fd);
//	fd = open("temp", O_WRONLY | O_CREAT | O_TRUNC);

	fd = open("temp", O_WRONLY | O_CREAT | O_TRUNC, 0644);

	if(fd < 0) {
	
		perror("open");
		return 0;
	}

	printf("fd : %d\n", fd);
	return 0;
}

/* output 
 
fd : 3

because fd 0, 1, 2 are reserved, then the availble lowest number 

*/



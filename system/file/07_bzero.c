#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {

	int fd, ret;
	char arr[20];
	bzero(arr, 20);	
	fd = open("temp", O_RDONLY);

	if(fd < 0) {
	
		perror("open");
		return 0;
	}
	
	read(fd, arr, 5);
	printf("%s\n", arr);
	return 0;
}

/* bzero(arr, 20); 
 	
   	all bits of arr are filled with 0
	
	arr = 0000 0000 0000 0000 0000

	then read(fd, arr, 5);
	
	arr = abcd e000 0000 0000 0000
	
 */

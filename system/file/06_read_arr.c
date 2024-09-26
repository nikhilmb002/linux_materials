// reading all characters from file using read sys call

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {

	char arr[20];
	int fd, ret;
	fd = open("temp", O_RDONLY);

	if(fd < 0) {
	
		perror("open");
		return 0;
	}

	read(fd, arr, 6);
	printf("%s\n", arr);
	return 0;
}

/* read sys call is not responsible for adding null char at the end of the data
 
solution 1:    
  
   ret = read(fd, arr, 5);
   arr[ret] = '\0';

solution 2: 

	using bzero function

solution 3: 

	using memset()
	
 */


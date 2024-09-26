#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {

	int fd, ret;
	char arr[20];
	memset(arr, 0, 20);	// with constant value 0 here fill with 20 bytes of arr

	fd = open("temp", O_RDONLY);

	if(fd < 0) {
		
		perror("open");
		return 0;
	}
	
	read(fd, arr, 5);
	printf("%s\n", arr);
	return 0;
}

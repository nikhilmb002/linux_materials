// reading a character from file using read sys call

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {

	char ch;
	int fd;
	fd = open("temp", O_RDONLY);

	if(fd < 0) {
	
		perror("open");
		return 0;
	}

	printf("fd : %d\n", fd);
	read(fd, &ch, 1);
	printf("ch = %c\n", ch);
	return 0;
}

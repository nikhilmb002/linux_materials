// reading all characters from file using read sys call

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {

	char ch;
	int fd, ret;
	fd = open("temp", O_RDONLY);

	if(fd < 0) {
	
		perror("open");
		return 0;
	}

	while((ret = read(fd, &ch, 1)) > 0) // once it reach the end of file returns 0
	printf("%c", ch);
	return 0;
}

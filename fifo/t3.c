#include "header.h"

int main() {

	char str[10]; float num;
	mkfifo("f1", 0666);
	perror("mkfifo");
	int fd = open("f1", O_RDWR);
	perror("open");
	printf("Enter the string\n");
	scanf("%s", str);
	write(fd, str, sizeof(str));
	read(fd, str, sizeof(str));
	printf("%s\n", str);
	close(fd);
	return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {

	int fd;
	mkfifo("f1", 0666);
	perror("mkfifo");
	fd = open("f1", O_RDWR);
	perror("open");
	char s[10]; float num;
	printf("Enter the num : ");
	scanf("%s", s);
	printf("\n");
	fsync(fd);
	write(fd, s, sizeof(s));
	read(fd, &num, sizeof(num));
	printf("%f\n", num);
	return 0;
}

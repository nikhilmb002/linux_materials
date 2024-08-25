#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {

	mkfifo("f2", 0666);
	perror("mkfifo");
	int a[5];
	printf("Enter the elements\n");
	for(int i = 0; i < 5; i++)
		scanf("%d", &a[i]);
	int fd = open("f2", O_RDWR);
	write(fd, a, sizeof(a));
	read(fd, a, sizeof(a));
	for(int i = 0; i < 5; i++)
		printf("%d", a[i]);
	close(fd);
	return 0;
}

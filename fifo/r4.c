#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
	
	int fd = open("f2", 0666);
	perror("open");
	int a[5]; 
	read(fd, a, sizeof(a));
	for(int i = 0; i < 5; i++) 
		a[i] = a[i] + 1;
	fsync(fd);
	write(fd, a, sizeof(a));
	close(fd);
	return 0;
}

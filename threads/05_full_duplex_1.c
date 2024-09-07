/* Full duplex communication using threads */

#include <stdio.h>
#include <pthread.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

void* thread1(void* p) {

	int fd;
	char buf[50];
	fd = open("f1", O_WRONLY);
	
	if(fd < 0) {
	
		perror("open");
		return 0;
	}

	while(1) {
	
		scanf(" %s", buf);
		write(fd, buf, strlen(buf)+1);
	}
}

void* thread2(void* p) {

	int fd;
	char buf[50];
	fd = open("f2", O_RDONLY);

	if(fd < 0) {
		
		perror("open");
		return 0;
	}

	while(1) {
	
		read(fd, buf, sizeof(buf));
		printf(" %s\n", buf);
	}
}

int main() {

	pthread_t t1, t2;
	mkfifo("f1", 0664);
	mkfifo("f2", 0664);
	pthread_create(&t1, 0, thread1, 0);
	pthread_create(&t2, 0, thread2, 0);
	while(1);	
}

















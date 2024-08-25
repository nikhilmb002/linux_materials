#include "header.h"

int main() {

	int r, ele;
	r = mkfifo("f1", 0666);
	perror("mkfifo");
	int fd = open("f1", O_RDWR);
	int a[5];
	ele = sizeof(a) / sizeof(a[0]);
	printf("Enter the elements\n");
	for(int i = 0; i < ele; i++)
		scanf("%d", &a[i]);
	write(fd, a, sizeof(a));
	return 0;
}

#include "header.h"

void sort_arr(int *a, int ele) {

	for(int i = 0; i < ele - 1; i++) {
	
		for(int j = 0; j < ele - i - 1; j++) {
		
			if(a[j] > a[j+1]) {
			
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;		
			}
		}
	}
}

int main() {

	int fd = open("f1", O_RDWR);
	perror("open");
	int a[5];
	read(fd, a, sizeof(a));
	sort_arr(a, 5);

	for(int i = 0; i < 5; i++)	
		printf("%d ", a[i]);	

	printf("\n");
	close(fd);
	return 0;
}

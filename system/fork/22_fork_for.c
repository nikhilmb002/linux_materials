#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

	int i;
	for(i = 0; i < 2; i++) {
	
		fork();
		printf("hello my pid : %d i : %d\n", getpid(), i);
	}

	return 0;
}

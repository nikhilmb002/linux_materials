#include <stdio.h>
#include <unistd.h>

int main() {
	
	int i;

	for(i = 0; i < 2; i++) {
	
		if(fork() == 0) {
		
			printf("pid : %d ppid : %d\n", getpid(), getppid());
		}

		else 

			break;
	}

	while(1);
}

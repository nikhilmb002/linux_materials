#include <stdio.h>
#include <unistd.h>
int main() {

	printf("process started execution\n");
	printf("pid of the process : %d\n", getpid());
       	printf("process terminated\n");	
}

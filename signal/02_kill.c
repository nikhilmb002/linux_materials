#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
int main(int argc, char** argv) {
	
	if(argc != 3) {
	
		printf("Usage : ./file pid signal\n");
		return 1;
	}
	
	kill(atoi(argv[1]), atoi(argv[2]));
	perror("kill");
	return 0;
}

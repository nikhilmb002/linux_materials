/* creating msg queue */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>

int main() {
	
	int id = msgget(5, IPC_CREAT | 0664);

	if(id < 0) {
		
		perror("msgget ");
		return 0;
	}

	printf("msgq created successfully\n");

	return 0;
}

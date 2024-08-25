/* crated shared memory segment */

#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>

int main() {
	
	int id;
	id = shmget(5, 20, IPC_CREAT | 0664);

	if(id  < 0) {
	
		perror("shmget");
		return 1;
	}

	printf("shared memory segment created...\n");
	return 0;
}

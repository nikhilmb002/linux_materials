/* read from shared memory segment */

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

int main() {
	
	int id, ret, *ptr;
	id = shmget(5, 20, IPC_CREAT | 0664);

	if(id < 0) {
	
		perror("shmget");
		return 1;
	}

	ptr = shmat(id, 0, 0);
	
	while(1) {
	
		ret = *ptr;
		printf("data : %d\n", ret);
		sleep(1);
	}
	
	return 0;
}

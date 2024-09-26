/* write data on shared memory segment */

#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <unistd.h>

int main() {

	int id, i = 1, *ptr;
	id = shmget(5, 20, IPC_CREAT | 0664);

	if(id < 0) {
	
		perror("shmget");
		return 0;
	}

	ptr = shmat(id, 0, 0);

	while(1) {

		*ptr = i;
		i++;
		sleep(1);
	}
	
	shmdt(ptr);
	return 0;
}

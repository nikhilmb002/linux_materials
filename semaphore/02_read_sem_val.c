/* program to read semaphore value using cla */

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>

int main(int argc, char **argv) {

	if(argc != 2) {
	
		printf("Usage : ./p2 semnum");
		return 1;
	}	

	int id, ret, index;
	id = semget(5, 3, IPC_CREAT | 0664);

	if(id < 0) {
	
		perror("semget");
		return 1;
	}

	index = atoi(argv[1]);
	ret = semctl(id, index, GETVAL);

	if(ret == -1) {
	
		perror("semctl");
		return 1;
	}
	
	printf("Semnum : %d Semvalue : %d\n", index, ret);
	
	return 0;	
}

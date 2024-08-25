/* program to change semaphore value using cla */

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char **argv) {

	if(argc != 3) {
	
		printf("Usage : ./p3 semnum semvalue\n");
		return 1;
	}

	int id, index, ret, semval;
	id = semget(5, 3, IPC_CREAT | 0664);

	if(id < 0) {
		
		perror("semget");
		return 1;	
	}

	index = atoi(argv[1]);
	semval = atoi(argv[2]);

	ret = semctl(id, index, SETVAL, semval);

	if(ret == -1) {
		
		perror("semctl");
		return 0;
	}

	printf("Semnum : %d value : %d\n", index, semval);
	
	return 0;

}

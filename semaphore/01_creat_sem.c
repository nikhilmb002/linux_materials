/* create 3 semaphore */

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/ipc.h>

int main() {

	int id;
	id = semget(5, 3, IPC_CREAT | 0664);
	
	if(id < 0) {
		
		perror("semget");
		return 1;
	}	

	printf("Semaphore created succesfully\n");
	return 0;
}

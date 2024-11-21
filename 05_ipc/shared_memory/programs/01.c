#include "header.h"
int main() {
	
	int id;
	id = shmget(5, 50, IPC_CREAT | 0644);
	
	if (id < 0) {

		perror("shmget");
		return 1;
	}
	
	printf("id : %d\n", id);
}

/* 
	
	id = shmget(5, 50, IPC_CREAT | 0664);
	
	Meaning of each argument 

		5 -> key 

			identifies the shared memory segment 

		50 -> size (bytes)

			Allocates 50 bytes of shared memory 
		
		IPC_CREAT -> 

			Creates the segment if it doesn't exist 

		0644 -> permissions 

			owner: read/write
			group: read/write
			others: read

		If a segment with key 5 already exists, it is opened, not created 
	
		Sample output : 

			id = 0

		   The id value may differ on differ system 


		Important notes 

			Shared memory is created in kernel space
			It exists even after the program exits
			It must be explicitly removed using shmctl() or ipcrm
			This program only creates the memory, it does not attach or use it

*/














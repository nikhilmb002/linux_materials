/* Sender */

#include "header.h"
int main() {

	char *p;
	int id;

	id = shmget(5, 50, IPC_CREAT | 0644);
	
	if (id < 0) {

		perror("shmget");
		return 1; 
	}

	printf("id = %d\n", id);
	
	p = shmat(id, 0, 0);
	
	printf("Enter the data\n");
	scanf("%s", p);
}

/* 
	id : shared memory ID (shmid)

	p  : pointer to shared memory (after attach)

	id = shmget(5, 50, IPC_CREAT | 0644);

		Meaning 

			5 -> key
			50 -> size (50 bytes)
			IPC_CREAT -> Create if not present 
			0644 -> Permissions 

		Returns a shared memory identifier 

	Attach shared memory 

		p = shmat(id, 0, 0);

		Attaches shared memory to process 
		Kernel chooses attach address
		Returns a pointer to shared memory 

	  After this, p behaves like a normal memory pointer 

	Write data into shared memory 

		scanf("%s", p);

		User enters data 
		Data is written directly into shared memory 
	
	
*/

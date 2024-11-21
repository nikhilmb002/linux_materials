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
	
	printf("Data : %s\n", p);
}

/* 
	
	Purpose 

		Access the same shared memory segment 
		Attach it to the process 
		Read and display stored data 
	
		id = shmget(5, 50, IPC_CREAT | 0644);
	
			uses the same key 5
			access the same shared memory segment 

		  if segment already created it, recover just opens it

		
		p = shmat(id, 0, 0);

			maps shared memory into receiver's address space
			p points to the same memory as sender's p 

		printf("Data : %s\n", p);
		
			Reads data written by sender
			No copying involved 
			Direct memory access 

		

	How both programs work together 

		1. Sender creates shared memory 
		2. Sender writes data into shared memory 
		3. Receiver attaches the same shared memory 
		4. Receiver reads the same data 

		No kernel copying :- very fast IPC  
	
	Important Notes 

		Both processes must use the same key 
		Shared memory persists after program exit
		Must be deleted explicitly using shmctl()
		No synchronization is used here (race condition possible)
		
*/















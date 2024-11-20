#include "header.h"
int main() {

	int id;
	id = msgget(4, IPC_CREAT | 0644);
	perror("msgget");
	printf("id = %d\n", id);
}

/* 
	What this program does 

		1. msgget(4, IPC_CREAT | 0664);

			* Tries to get or create a system v message queue 
			* 4 :- message queue key
			* IPC_CREAT :- crete the queue if it doesn't already exist 
			* 0644 :- Permissions 

				* Owner : read/write
				* group : read
				* others: read 

		2. Return Value

			On success -> returns a message queue  identifier (msqid) (a non -ve number)
		
			On failure : returns -1

		3. perror ("msgget");

			Prints an error message only if an error occured 
			if no error :- prints:
					
					msgget: Success 

		4. printf("id = %d\n", id);

				printfs the returned message queue ID 


		Possible Output :- 

			case 1 : Queue created successfully (or already exists)

					msgget: Success
					id = 0

					 or 

					msgget: Success
					id = 3

					id value may differ on each system 
					any non -ve value means success

			case 2 : Error (example: permission denied)

					msgget: Permission denied
					id = -1
*/

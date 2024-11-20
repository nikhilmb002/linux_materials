/* Receiver Program */

#include "header.h"
struct msgbuf {

	long mtype;
	char data[20];
};

int main(int argc, char **argv) {

	struct msgbuf v;	
	int id;

	if (argc != 2) {

		printf("Usage : ./rcv type\n");
		return 1;
	}

	id = msgget(5, IPC_CREAT | 0644);
	
	perror("msgget");
	printf("id : %d\n", id);

	msgrcv(id, &v, sizeof(v.data), atoi(argv[1]), 0);
	perror("msgrcv");
	printf("Data : %s\n", v.data);
}

/* 
	
	Purpose of receiver 
	
		* Waits for a message of a specific type 
		* Reads and prints the message

		msgrcv(id, &v, sizeof(v.data), atoi(argv[1]), 0);
		
			Read message from queue

				Store into v

				Receive message of given type

				Wait until message is available

				📌 If no message → program blocks (waits)

	In System V message queues, mtype must be of type long. Using int causes message type mismatch and msgrcv() may block indefinitely, especially on 64-bit systems.

	
	Again we enter same type (mean no type of msg in msgq) then msgrcv() is block

*/

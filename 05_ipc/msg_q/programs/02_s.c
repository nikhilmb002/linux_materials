/* Sender program */

#include "header.h"
struct msgbuf {

	long mtype;
	char data[20];
};

int main(int argc, char **argv) {
	
	struct msgbuf v;
	int id;

	if (argc != 3) {

		printf("Usage : ./snd type data\n");
		return 1;
	}

	id = msgget(5, IPC_CREAT | 0644);
	
	perror("msgget");
	printf("id : %d\n", id);

	v.mtype = atoi(argv[1]);
	strcpy(v.data, argv[2]);
	msgsnd(id, &v, strlen(v.data)+1, 0);
	perror("msgsnd");
}


/* 

	Message structure 

		This structure defines what one message looks like. 

		mtype :- message type (number used to identify message)
		data  :- actual message text 

		Rule : mtype must be greater than 0 

		
		Sender needs 2 inputs: 
		
			1. msg type 
			2. msg data

		Create access message queue 

			id = msgget(5, IPC_CREAT | 0664);
			
				5 :- msg queue key 
				IPC_CREAT :- Create queue if not present 
				0644 :- permissions 

				kernel returns a msgq id 

		Print status 

			if success : 

				msgget: Success
				id : 0

		Fill message structure 

			v.mtype = atoi(argv[1]);
			strcpy(v.data, argv[2]);


			Example : 

				./snd 2 hi 

				stored as : 

					mtype = 2
					data = "hi"
					
		Send the message 

			msgsnd(id, &v, strlen(v.data)+1, 0);

			This sends the message into the queue 

				sends only data, not mtype 
				0 -> wait if queue is full				

*/



/* 
	Why did mtype = 0 work in some program?
	
		Linux may not strictly reject mtype = 0, but it is invalid by definition. The receiver used msgtyp = 0, which receives any message, making it appear to work. This behavior is non-portable and should be avoided.

*/
















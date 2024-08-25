/* creating msg queue and sending message */

#include <stdio.h>
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>

struct msgbuf {

	long mtype;
	char mtext[2];
};

int main(int argc, char **argv) {

	if(argc != 3) {
	
		printf("Usage : ./a.out mtype message\n");
		return 0;
	}
	
	int id = msgget(7, IPC_CREAT | 0664);

	if(id < 0) {
		
		perror("msgget");
		return 0;
	}

	struct msgbuf v;

	v.mtype = atoi(argv[1]);
	strcpy(v.mtext, argv[2]);

	int ret = msgsnd(id, &v, strlen(v.mtext)+1, 0);

	if(ret == -1) {
	
		perror("msgsnd");
		return 0;
	}
	
	printf("msg sent succesfully\n");
}

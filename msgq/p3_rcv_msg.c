/* reading msg from msgque */

#include <stdio.h>
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>

struct msgbuf {
	
	long mtype;
	char mtext[50];
};

int main(int argc, char **argv) {

	if(argc != 2) {
	
		printf("Usage : ./p3 mtype\n");
		return 0;
	}
		
	int id = msgget(7, IPC_CREAT | 0664);

	if(id < 0) {
	
		perror("msgget");
		return 0;
	}

	struct msgbuf v;
	
	int ret = msgrcv(id, &v, sizeof(v.mtext)+1, atoi(argv[1]),  0);

	if(ret == -1) {
	
		perror("msgrcv");
		return 0;
	}

	printf("message reading successfull\n");
	printf("msg   : %s\n", v.mtext);
	printf("mtype : %d\n", v.mtype);

	return 0;
}

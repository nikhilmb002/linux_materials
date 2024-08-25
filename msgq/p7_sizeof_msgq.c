/* print sizeof msgq */

#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <string.h>

int main() {

	int id, ret;
	struct msqid_ds v;
	id = msgget(5, IPC_CREAT | 0664);

	if(id < 0) {
	
		perror("msgget");
		return 1;
	}

	msgctl(id, IPC_STAT, &v);
	printf("msgq size : %ld\n", v.msg_qbytes);
	return 0;
}

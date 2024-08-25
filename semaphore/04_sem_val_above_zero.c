/* sem_op > 2 */

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>

int main() {

	int id; 
	struct sembuf v;
	id = semget(5, 3, IPC_CREAT | 0664);

	if(id < 0) {
	
		perror("semget");
		return 1;
	}

	v.sem_num = 0;
	v.sem_op = 2;
//	v.sem_flg = 0;
	v.sem_flg = SEM_UNDO;

	printf("before semop...\n");
	printf("wait...\n");
	semop(id, &v, 1);
	printf("after semop...\n");
	printf("signalled\n");
	while(1);
	return 0;
}

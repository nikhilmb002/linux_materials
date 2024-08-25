/* sem_op < 0 */

#include <stdio.h>
#include <sys/sem.h>
#include <fcntl.h>

int main() {

	while(1) {

		int id; 
		struct sembuf v;
		id = semget(5, 3, IPC_CREAT | 0664);

		if(id < 0) {

			perror("semget");		
			return 0;
		}

		v.sem_num = 0;
		v.sem_op = -1;
		v.sem_flg = 0;

		printf("Before...\n");
		semop(id, &v, 1);

		printf("After...\n");

	}

	return 0;
}

/* both process write data one by one in data file using semaphore */

#include <stdio.h>
#include <sys/sem.h>
#include <fcntl.h>
#include <unistd.h>

int main() {

	struct sembuf v;
	int id, fd, i;
	char a[] = "123456";
	
	id = semget(5, 3, IPC_CREAT | 0664);

	if(id < 0) {
	
		perror("semget");
		return 1;
	}

	fd = open("data", O_RDWR | O_APPEND | O_CREAT , 0664);

	if(fd < 0) {
		
		perror("open");
		return 1;
	}

	v.sem_num = 2;
	v.sem_op = 0;
	v.sem_flg = 0;

	printf("Before...\n");
	semop(id, &v, 1);
	semctl(id, 2, SETVAL, 1);	
	printf("After...\n");

	for(i = 0; a[i]; i++) {

		write(fd, &a[i], 1);
		sleep(1);
	}


	semctl(id, 2, SETVAL, 0);
	printf("Done...\n");

	return 0;	
}


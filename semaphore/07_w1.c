/* both process write data one by one characters alternatively in data file using semaphore */

#include <stdio.h>
#include <sys/sem.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {

	int id, fd, i = 0;
	struct sembuf v;
	id = semget(5, 3, IPC_CREAT | 0664);

	if(id < 0) {
		
		perror("semget");
		return 1;
	}

	fd = open("data", O_RDWR | O_APPEND | O_CREAT, 0664);

	if(fd < 0) {

		perror("open");
		return 1;
	}

	char a[] = "1234567";


		v.sem_num = 0;
		v.sem_op = -1;
		v.sem_flg = 0;

	while(i < strlen(a)) {

		semop(id, &v, 1);
		printf("writing %c\n", a[i]);
		write(fd, &a[i], 1);
		i++;
		sleep(1);
		semctl(id, 0, SETVAL, 0);
	}

	printf("completed...\n");
	close(fd);

	return 0;
}

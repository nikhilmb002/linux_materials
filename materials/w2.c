#include"header.h"

void main()
{

int id=semget(4,5,IPC_CREAT|0664);
	if(id<0)
	{
	perror("semget");
	return;
	}

int fd=open("DATA",O_WRONLY|O_APPEND|O_CREAT,0664);
	if(fd<0)
	{
	perror("open");
	return;
	}

struct sembuf v;
char ch;
v.sem_num=2;
v.sem_op=0;
v.sem_flg=0;
printf("Before...\n");
semop(id,&v,1);
semctl(id,2,SETVAL,1);
printf("After...\n");
for(ch='A';ch<='Z';ch++)
{
	write(fd,&ch,1);
	sleep(1);
}
semctl(id,2,SETVAL,0);
printf("Done...\n");

}





#include"header.h"
void main()
{
int id;
	id=shmget(4,50,IPC_CREAT|0664);

	if(id<0)
	{
	perror("shmget");
	return;
	}
printf("id=%d\n",id);
char *p;
	p=shmat(id,0,0);
	perror("shmat");

	printf("Data=%s\n",p);


}

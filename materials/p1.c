#include"header.h"
void * thread_1(void *p)
{
//	printf("Data=%s\n",(char *)p);
	while(1)
	printf("In thread_1 pid=%d tid=%ld\n",getpid(),pthread_self());

}

void main()
{
pthread_t t1;
	pthread_create(&t1,0,thread_1,"Hello");
	pthread_exit(0);
	//printf("r=%d\n",r);
//	while(1);
//	printf("In main pid=%d tid=%ld t1=%ld\n",getpid(),pthread_self(),t1);
}

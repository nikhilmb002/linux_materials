#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/sysinfo.h>
#include <unistd.h>

int main() {

	struct sysinfo info;

	if(sysinfo(&info) != 0) {

		perror("sysinfo");
		return 1;
	}	

	while(1) {

		printf("Free RAM : %.2f MB\n", (double)info.freeram/(1024 * 1024));
		sleep(1);

	}

	return 0;
}

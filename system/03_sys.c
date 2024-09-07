#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

	printf("p3 process started execution ...\n");
	sleep(2);
	printf("p4 process going to load\n");
	system("./p4");
	sleep(2);
	printf("in p3 process terminated ...\n");
}

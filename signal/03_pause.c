#include <stdio.h>
#include <unistd.h>
int main() {

	printf("Hello world .............%d\n", getpid());
	pause();
	printf("Bye..........\n");
}

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void my_isr(int n) {
	
	printf("in isr ...\n");
}

int main() {

	printf("Hello world ... %d\n", getpid());
	signal(2, my_isr);
	printf("Bye ...\n");
	while(1);
}

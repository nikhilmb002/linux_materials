// cow example`

#include <stdio.h>
#include <unistd.h>

int main() {

	int i = 10;

	if(fork() == 0) {
		
		sleep(2);	
		printf("in child i = %d addr of i = %u\n", i, &i);
	}

	else {
		i = 20;	
		printf("in parent i = %d addr of i = %u\n", i, &i);
	}

	return 0;
}

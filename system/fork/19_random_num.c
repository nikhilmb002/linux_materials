#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	
	int a[5], i;
	
	srand(getpid());	// here we get different numbers because every time we run pid will changes...so seed value also changes

	for(i = 0; i < 5; i++) 

		a[i] = rand();

	printf("sequence of numbers are ...\n");

	for(i = 0; i < 5; i++) 

		printf("%d ", a[i]);
}

// seed value change then sequence of numbers also change
// seed value same sequence of numbers also same

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {

	int a[5], i;
	srand(getpid());

	for (i = 0; i < 5; i++) 

		a[i] = rand() % 1000;
	
	printf("sequence of numbers are \n");
	
	for (i = 0; i < 5; i++)	
		
		printf("%d\n", a[i]);

	return 0;
}

/* 
	srand(getpid()) uses the PID as the seed value. 
	since the PID is different for each run, the random sequence change every time.

	rand() % 1000 limits the random number range. 
	The modulo operator % gives the remainder, so the result is always between 0 and 999

	Using % is a common way to control the size (no.of digits) of random number and keep them within a require range. 

	General rule : 

		rand() % N 	-> 0 to N-1
		rand() % N + 1	-> 1 to N 

	This technique is used to control the range of random numbers 
	and generate values within a required boundary 

*/

#include <stdio.h>
#include <stdlib.h>
int main() {

	int a[5], i;
	srand(200);
	for(i = 0; i < 5; i++)
		a[i] = rand();
	
	printf("sequence of numbers are \n");
	for (i = 0; i < 5; i++)
		printf("%d\n", a[i]);

	return 0;
}

/* 
	This program generates 5 random numbers using rand()

	The function srand(200) sets a fixed seed value 

	Because the see is constant, read() produces the same sequence of numbers every time program is executed

	So, each run of this program will print the exact same numbers

	To get different numbers on each run, the seed must change 
*/

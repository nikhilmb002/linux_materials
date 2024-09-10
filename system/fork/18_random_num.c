#include <stdio.h>
#include <stdlib.h>
int main() {
	
	int a[5], i;
	srand(200);	// because of seed value same value will repeat when we run again and again because of the same seed value

	for(i = 0; i < 5; i++) 

		a[i] = rand();

	printf("sequence of numbers are ...\n");

	for(i = 0; i < 5; i++) 

		printf("%d ", a[i]);
}

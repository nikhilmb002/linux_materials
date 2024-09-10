#include <stdio.h>
#include <stdlib.h>
int main() {
	
	int a[5], i;
	srand(200);	// because of seed value same value will repeat when we run again and again because of the same seed value

	for(i = 0; i < 5; i++) 

		a[i] = rand() % 1000;	// min value 0 and max 999

	// a[i] = rand() % 10 + 1; 	// min val 1 and max 10

	printf("sequence of numbers are ...\n");

	for(i = 0; i < 5; i++) 

		printf("%d ", a[i]);

	printf("\n");
}

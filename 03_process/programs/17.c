/* random number generation */

#include <stdio.h>
#include <stdlib.h>
int main() {
	
	int r1, r2;
	srand(100);
	r1 = rand();
	r2 = rand();
	printf("%d\n", r1);
	printf("%d\n", r2);
}


#include <stdio.h>
#include <unistd.h>

int main() {

	printf("Hii...\n");
	fork();
	fork();
	printf("Hello...\n");
	return 0;
}

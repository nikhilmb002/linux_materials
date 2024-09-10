#include <stdio.h>
#include <unistd.h>

int main() {

	int res;
	
	if((res = fork()) == 0) {
	
		printf("in child res : %d\n", res);
	}

	else {
	
		printf("in parent res : %d\n", res);
	}
}

#include <stdio.h>
#include <unistd.h>

int main() {
	
	int i = 0;

	while(1) {
	
		printf("hello\n");
		sleep(1);
		i++;

		if(i == 3)

			close(1);	// 1 is file descriptor stdout
	}
}

/* once this process starts execution 

	hello 
	hello
	hello

	when i=3 it will close stdout file descriptor then it is not possible to display on screen
	
*/

#include <stdio.h>
#include <unistd.h>
int main() {

	printf("Hi...\n");	// line_1
	fork();			// line_2
	fork();			// line_3
	printf("Bye...\n");	// line_4
}


/* 
	$ cc p4.c -o p4
	$ ./p4 

	first fork() on line line_2 have child 

		main() {
			
			.....
			.....
			fork();		// line_5
			printf("Bye...\n");
		}

	second fork() on line line_3 have child 

		main() {

			.....
			.....
			.....

			printf("Bye...\n");
		}

	due to fork() on line line_5 

		main() {

			.....
			.....
			.....		
			.....

			printf("Bye...\n");
		}	






	so the output : 

		Hi...
		Bye...
		Bye...
		Bye...
		Bye...
	
*/

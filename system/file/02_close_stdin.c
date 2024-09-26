// stdin stream with fd 0

#include <stdio.h>
#include <unistd.h>

int main() {

	int i = 0;
	char ch;

	while(1) {

		printf("Enter char\n");
		scanf(" %c", &ch);
		sleep(1);
		i++;

		if(i == 3)

			close(0);
	}
}

/* 
 	_________
	|	|
	| code	|<----- stdin <---- std input
	|	|
	---------

	if we close(0) then stdin will close

*/

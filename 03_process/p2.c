/*
   system - execute a shell command 
  
   int system (const char* command);

*/
  
#include <stdio.h>
#include <stdlib.h>

int main() {

	printf("Hello ...\n");
	system("ls");
	printf("Bye\n");
}

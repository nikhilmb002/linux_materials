// wap to create the named pipe

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {

	mkfifo("np", 0664);	
	perror("mkfifo");

	return 0;
}

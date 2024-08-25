#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {

	int fd = open("f1", O_RDWR);
	perror("open");
	char r[10]; float rev = 0.0, dec = 1.0; 
	read(fd, r, sizeof(r));
	int i, j;
	for(i = 0; r[i]; i++) {
	
		if(r[i] >= '0' && r[i] <= '9') {
		
			rev = rev * 10 + (r[i] - 48);
		}

		else if(r[i] == '.') {
		
			dec = dec / 10 + (r[i] - 48);
		}

		else 
			break;	
	}

	rev = rev + dec;
	printf("%f\n", rev);
	write(fd, &rev, sizeof(rev));
	return 0;
}

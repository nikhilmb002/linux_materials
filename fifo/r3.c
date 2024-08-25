#include "header.h"

int check_pal(char *str) {

	int flag = 1;
	
	for(int i = 0, j = strlen(str) - 1; i < j; i++, j--) {
	
		if(str[i] != str[j]) {

			return 0;
		}
	
	}

	return flag;
}

int main() {

	char str[10];
	mkfifo("f1", 0666);
	perror("mkfifo");
	int fd = open("f1", O_RDWR);
	perror("open");
	read(fd, str, sizeof(str));
	int res = check_pal(str);
	char msg1[10] = "pal";
	char msg2[10] = "not pal";
	
	if(res == 1)

		write(fd, msg1, strlen(msg1) + 1);
	else 
		write(fd, msg2, strlen(msg2) + 1);

	close(fd);

	return 0;
}

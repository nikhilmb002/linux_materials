#include <stdio.h>
int main() {
	
	printf("hello...\n");
	while(1);
}

/* 

./p4 &
[1] 9021
nikhil@nikhil:~/Desktop/ME/linux/process$ hello...

nikhil@nikhil:~/Desktop/ME/linux/process$ ps
    PID TTY          TIME CMD
   4751 pts/1    00:00:00 bash
   9021 pts/1    00:00:03 p4
   9022 pts/1    00:00:00 ps
nikhil@nikhil:~/Desktop/ME/linux/process$ kill -19 9021

[1]+  Stopped                 ./p4
nikhil@nikhil:~/Desktop/ME/linux/process$ ps
    PID TTY          TIME CMD
   4751 pts/1    00:00:00 bash
   9021 pts/1    00:00:17 p4
   9024 pts/1    00:00:00 ps
nikhil@nikhil:~/Desktop/ME/linux/process$ kill -18 9021
nikhil@nikhil:~/Desktop/ME/linux/process$ ps
    PID TTY          TIME CMD
   4751 pts/1    00:00:00 bash
   9021 pts/1    00:00:18 p4
   9025 pts/1    00:00:00 ps
nikhil@nikhil:~/Desktop/ME/linux/process$ ps

*/

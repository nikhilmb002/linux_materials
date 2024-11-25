#include "header.h"
int main() {
	
	struct flock v;

	int fd = open("data", O_RDWR | O_CREAT, 0644); // opens file data for read/write 
	
	v.l_type = F_WRLCK;	// write lock (exclusive lock)
	v.l_whence = SEEK_SET;	// starting position is beginning of file 
	v.l_start = 0;		// lock starts at byte 0 
	v.l_len = 0;		// lock till end of file 
				// so his locks entire file 

	/*
		Locked Region 	
	
		|==============================|
		0                            EOF	
	*/
	
	fcntl(fd, F_SETLKW, &v);
	
	write(fd, "HELLO\n", 6);

	sleep(10);

	v.l_type = F_UNLCK;		// unlock file 
	fcntl(fd, F_SETLK, &v);		// 
}

/* 
	
	Purpose of the program 

		* opens a file 
		* applies a write lock on the file 
		* writes "HELLO"
		* Keeps the lock for 10 seconds 
		* Releases the lock 

		This prevent other processes from writing to the file at the same time 

		struct flock v;
			
			This structure tells the kernel 
	
				which part of file to lock 	
				what type of lock 

		fcntl(fd, F_SETLKW, &v);

			F_SETLKW -> set lock & wait
			if another process holds lock : 

				this call bloks until lock becomes free 



		How to test 

			terminal 1 : ./a.out 

			terminal 2 (during sleep) : ./a.out 


			second terminals waits until 1st finishes 


*/







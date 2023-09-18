/*
Parent fork child process
Child process inherit the file descriptor of the parent.
file position can be updated from both processes
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include <sys/wait.h>

int main()
{
	char c;
	int fd = open("sample.txt", O_RDONLY, 0);
	if (fork() == 0 ){
		read(fd, &c, 1); // In the child read one character from Minecraft - character 'M'
		printf("Child --- c = %c\n", c);
		return 0; 
	}
	else {
		wait(0);
		read(fd, &c, 1); // In the parent read one character from Minecraft - character 'i'
		printf("Parent --- c = %c\n", c);
	}

	exit(0);
}



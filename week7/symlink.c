/*
This program creates symbolic links
*/

#define _POSIX1_SOURCE 2
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    char fn[] = "test.file"; // source file
    char sln[] = "test.symlink"; // symbolic link
    int fd;

    if ((fd = creat(fn, S_IWUSR)) < 0)
        perror("creat() error");
    else
    {
        close(fd);
        puts("before symlink()");
        system("ls -il test.*");
        if (symlink(fn, sln) != 0)
        {
            perror("symlink() error");
            unlink(fn);
        }
        else
        {
            printf("after symlink()\n");
            system("ls -il test.*");
            unlink(fn);

            printf("after first unlink()\n");
            system("ls -il test.*");
            unlink(sln);

            printf("after second unlink()\n");
            system("ls -il");
        }
    }
}
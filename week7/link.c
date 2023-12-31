/*
Creates a hardlink to a file
Delete / Unlink the original file and the link
*/

#define _POSIX_SOURCE
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    char fn[] = "link.example.file"; // Original file
    char ln[] = "link.example.link"; // Hard link of the original
    int fd;

    if ((fd = creat(fn, S_IWUSR)) < 0)
        perror("creat() error");
    else
    {
        close(fd);
        if (link(fn, ln) != 0) // link; creates a hard link vs symlink: creates a symbolic link
        {
            perror("link() error");
            unlink(fn);
        }
        else
        {
            //unlink(fn); // Delete the original file
            //unlink(ln); // Delete the hard link
        }
    }
}
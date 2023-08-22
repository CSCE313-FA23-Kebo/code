/*
This program prints the user ID and group ID of the process owner
*/

#include "apue.h"
int main(void)
{
    printf("uid = %d, gid = %d\n", getuid(), getgid());
    exit(0);
}
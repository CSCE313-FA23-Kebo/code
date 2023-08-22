/*
This program prints the running process's ID
*/

#include "apue.h"
int main(void)
{
    printf("Hello from process ID %ld\n", (long)getpid());
    exit(0);
}
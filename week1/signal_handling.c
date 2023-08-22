/*
This program reads commands from standard input and execute them.
A signal handler handles incoming SIGINT signals.
*/

#include "apue.h"
#include <sys/wait.h>

/* our signal-catching function */
static void sig_int(int);

int main(void)
{
    char buf[MAXLINE]; /* from apue.h */
    pid_t pid;
    int status;

    if (signal(SIGINT, sig_int) == SIG_ERR)
        printf("signal error");
    printf("%% "); /* print prompt (printf requires %% to print %) */

    while (fgets(buf, MAXLINE, stdin) != NULL)
    {
        if (buf[strlen(buf) - 1] == '\n')
            buf[strlen(buf) - 1] = 0; /* replace newline with null */
        if ((pid = fork()) < 0)
        {
            printf("fork error");
        }
        else if (pid == 0)
        { /* child process */
            execlp(buf, buf, (char *)0);
            printf("couldn’t execute: %s", buf);
            exit(127);
        }
        /* parent process */
        if ((pid = waitpid(pid, &status, 0)) < 0)
            printf("waitpid error");
        printf("%% ");
    }
    exit(0);
}

void sig_int(int signo)
{
    printf("Interrupt handled\n%% ");
}
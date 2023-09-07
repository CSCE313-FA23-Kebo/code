/*
Example: execvp
 */

#include <iostream>
#include <stdexcept>
#include <unistd.h>
using namespace std;

int main()
{
    char *args[] = {"ls", "-l", "-a", NULL};
    cout << "=====BEFORE========" << endl;
    execvp(args[0], args);
    cout << "======AFTER========" << endl;

    // e.g for the PA1
    pid_t server_pid = fork();
    int buffer_size;
    char *args[] = {"./server", "-m", buffer_size};
    execvp(args[0], args);
}


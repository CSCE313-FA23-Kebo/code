/*
Example: execle
 */

#include <iostream>
#include <stdexcept>
#include <unistd.h>
using namespace std;

int main()
{
    const char *file = "/usr/bin/bash";
    const char *arg1 = "-c";
    const char *arg2 = "echo $ENV1 $ENV2!";
    const char *const env[] = {"ENV1=Mario", "ENV2=Cart", NULL};
    execle(file, file, arg1, arg2, NULL, env);
    return 0;
    /**
     * 
     * The command executed is: /usr/bin/bash -c echo $ENV1 $ENV2
    */
}

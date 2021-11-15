#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
int value = 5;
int main()
{
    pid_t pid;
    pid = fork();
    fork();
    if (pid == 0)
    {
        value = value + 15;
        printf("child : value = %d\n", value);

        return 0;
    }
    else if (pid > 0)
    {
        /* code */
        // wait(NULL);
        printf("Parent : value = %d\n", value);
    }
}
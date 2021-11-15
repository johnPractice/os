#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
int main()
{
    if (fork() && (!fork()))
    {
        if (fork() || (fork()))
        {
            fork();
        }
    }
    printf("2");
    printf("\n");
    return 0;
}
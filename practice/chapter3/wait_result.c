#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int pid;
    pid = fork();
    if (pid < 0)
    {
        printf("Error for creating new process\n");
    }
    else if (pid == 0)
    {
        printf("this is child process\n");
        return 0;
    }

    // get child process status exit code
    int child_return_status;
    wait(&child_return_status);
    printf("%d is value of child process value\n", child_return_status);
    return 0;
}
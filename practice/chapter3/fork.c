#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    // create pid with type of pid_t
    pid_t pid, pid2;
    int result_child_process1;
    // create new child
    pid = fork();
    // check for error
    if (pid < 0)
    {
        fprintf(stderr, "Fork Error");
        return 1;
    }
    // check child process
    // child process is 0
    // parent is not 0 have another id
    else if (pid == 0)
    {
        // can execut the comand with the file and argumant
        int a = execlp("/bin/ls", "ls", "-l", NULL);
        printf("result of func is %d\n", a);
    }
    // parent
    else
    {
        // paranet wait
        int wait_result = wait(&result_child_process1);
        printf("result of wait is pid: %d \n", wait_result);
        printf("argument pass to wait is result returnnig on child process: %d \n", result_child_process1);
        printf("***************\n");
        printf("Child complete");
    }
    pid2 = fork();
    // check for error
    if (pid2 < 0)
    {
        fprintf(stderr, "Fork Error");
        exit(1);
    }
    // check child process
    // child process is 0
    // parent is not 0 have another id
    else if (pid2 == 0)
    {
        // can execut the comand with the file and argumant
        int a = execlp("/bin/ls", "ls", "-la", NULL);
        printf("result of func is %d\n", a);
        exit(0);
    }
    // parent
    else
    {
        // paranet not  wait
        printf("***************\n");
        printf("2Child complete2\n");
    }
    return 0;
}
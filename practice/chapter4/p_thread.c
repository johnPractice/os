#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int sum = 0;                /*shared data for using for thread's*/
void *runner(void *params); /* threads call this function */

int main(int args, char *argv[])
{
    printf("in the  main\n");

    pthread_t thread_id;
    pthread_attr_t attr; /* set of thread attributes */
    /* set the default attributes of the thread */
    pthread_attr_init(&attr);
    /* create the thread */
    printf("in the  create thread\n");

    pthread_create(&thread_id, NULL, runner, argv[1]);
    /* wait for the thread to exit */
    printf("wait for thread call\n");

    pthread_join(thread_id, NULL);

    printf("sum = %d \n", sum);
    return 0;
}

/* The thread will execute in this function */
void *runner(void *param)
{
    printf("in the  runner\n");
    int i, upper = atoi(param);
    sum = 0;
    for (i = 1; i <= upper; i++)
        sum += i;
    pthread_exit(0); /*for exiting calling thread*/
}
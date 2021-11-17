

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUM_THREADS 10

int sum = 0;                 /*shared data for using for thread's*/
void *runner(void *params);  /* threads call this function */
void *runner2(void *params); /* threads call this function */

int main(int args, char *argv[])
{
    printf("in the  main\n");
    int p_id;
    /* an array of threads to be joined upon */
    pthread_t workers[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++)
    {
        if (i % 2 == 0)
        {
            p_id = pthread_create(&workers[i], NULL, runner2, argv[2]);
        }
        else
        {
            p_id = pthread_create(&workers[i], NULL, runner, argv[1]);
        }
        pthread_join(workers[i], NULL);
        printf("resutl of pthread is %d\n", p_id);
        printf("sum = %d \n", sum);
    }
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
void *runner2(void *param)
{
    printf("in the  runner2\n");
    int i, upper = atoi(param);
    printf("gii upper%d\n", upper);
    sum = 1;
    for (i = 1; i <= upper; i++)
        sum = sum * i;
    pthread_exit(0); /*for exiting calling thread*/
}
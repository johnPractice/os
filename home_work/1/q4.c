#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
int main()
{
    // 1x means add x number to queue
    // 2xy means remove from x queue  remove y element
    long int q, n; //n means count of actions
    scanf("%ld %ld", &q, &n);
    int *queue = (int *)malloc(n * sizeof(int));

    long int pointerToQueue = 0;

    int *pointerToTailQueue;
    pointerToTailQueue = (int *)malloc(n * sizeof(int));
    for (long int i = 0; i < q; i++)
    {
        pointerToTailQueue[i] = 0;
    }

    long long int *sumOfUntil;
    sumOfUntil = (long long int *)malloc(n * sizeof(long int));
    long long int pointerTosumOfUntil = 0;

    // long int *result;
    // result = (long int *)malloc(n * sizeof(long int));
    // long int pointerToResult = 0;

    long long int checkInput, firstArg;
    for (long int i = 0; i < n; i++)
    {
        scanf("%lld %lld", &checkInput, &firstArg);
        if (checkInput == 1)
        {
            queue[pointerToQueue] = firstArg;
            pointerToQueue++;
            if (pointerTosumOfUntil == 0)
                sumOfUntil[0] = firstArg;
            else
                sumOfUntil[pointerTosumOfUntil] = sumOfUntil[pointerTosumOfUntil - 1] + firstArg;
            pointerTosumOfUntil++;
        }
        else if (checkInput == 2)
        {
            long int countRemove;
            scanf("%ld", &countRemove);

            long long int tailQueueSelected = pointerToTailQueue[firstArg - 1];

            if (tailQueueSelected == 0)
            {
                pointerToTailQueue[firstArg - 1] = countRemove;
                printf("%lld\n", sumOfUntil[countRemove - 1]);
            }
            else
            {
                long long int newTail = pointerToTailQueue[firstArg - 1] + countRemove;
                pointerToTailQueue[firstArg - 1] = newTail;
                printf("%lld", sumOfUntil[newTail - 1] - sumOfUntil[pointerToTailQueue[firstArg - 1] - 1]);
            }

            // result[pointerToResult] = sumOfRemove;

            // pointerToResult++;
        }
    }
    // for ( long int i = 0; i < pointerToResult; i++)
    // {
    //     printf("%Ld\n", result[i]);
    // }

    return 0;
}
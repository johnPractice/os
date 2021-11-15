#include <stdlib.h>
#include <stdio.h>

int main()
{
    // 1x means add x number to queue
    // 2xy means remove from x queue  remove y element
    long int q, n; //n means count of actions
    scanf("%ld %ld", &q, &n);
    long int queue[n];
    long int pointerToQueue = 0;

    long int pointerToTailQueue[q];
    for (int i = 0; i < q; i++)
    {
        pointerToTailQueue[i] = 0;
    }

    int halfLength = ((int)n / 2) + 1;
    long int sumOfUntil[n];
    long int pointerTosumOfUntil = 0;

    long int result[halfLength];
    long int pointerToResult = 0;

    long int checkInput, firstArg;
    for (int i = 0; i < n; i++)
    {
        scanf("%ld %ld", &checkInput, &firstArg);
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
            // printf("count remove %ld\n and first arg%ld\n", countRemove, firstArg);
            int sumOfRemove = 0;
            int tailQueueSelected = pointerToTailQueue[firstArg - 1];

            // printf("selected tail %ld\n", tailQueueSelected);
            if (tailQueueSelected == 0)
            {
                // printf("in the if\n");
                sumOfRemove = sumOfUntil[countRemove - 1];
                pointerToTailQueue[firstArg - 1] = countRemove;
            }
            else
            {
                int newTail = pointerToTailQueue[firstArg - 1] + countRemove;
                sumOfRemove = sumOfUntil[newTail - 1] - sumOfUntil[pointerToTailQueue[firstArg - 1] - 1];
                pointerToTailQueue[firstArg - 1] = newTail;
            }

            result[pointerToResult] = sumOfRemove;
            pointerToResult++;
        }
    }
    for (int i = 0; i < pointerToResult; i++)
    {
        printf("%ld\n", result[i]);
    }

    return 0;
}
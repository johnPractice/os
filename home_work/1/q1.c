#include <stdlib.h>
#include <stdio.h>

int main()
{
    int countNumber;
    scanf("%d", &countNumber);
    int numbers[countNumber];
    for (int i = 0; i < countNumber; i++)
    {
        int temp;
        scanf("%d", &temp);
        numbers[i] = temp;
    }
    int MAX_TOTAL = 0;
    int MAX_TOTAL_HERE = 0;
    for (int j = 0; j < countNumber; j++)
    {
        MAX_TOTAL_HERE = MAX_TOTAL_HERE + numbers[j];

        if (MAX_TOTAL_HERE > MAX_TOTAL)
        {
            MAX_TOTAL = MAX_TOTAL_HERE;
        }
        if (MAX_TOTAL_HERE < 0)
            MAX_TOTAL_HERE = 0;
    }
    printf("%d\n", MAX_TOTAL);

    return 0;
}
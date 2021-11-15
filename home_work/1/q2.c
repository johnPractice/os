#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct Person
{
    char name[200];
    int monyRemain;
};

int main()
{

    // name length max is 200
    int numberOfPeaple;
    scanf("%d", &numberOfPeaple);
    struct Person persons[numberOfPeaple];
    for (int i = 0; i < numberOfPeaple; i++)
    {
        persons[i].monyRemain = 0;
        scanf("%s", persons[i].name);
    }

    for (int i = 0; i < numberOfPeaple; i++)
    {
        char personName[200];
        scanf("%s", personName);
        int moneyToGive, numberOfFriend;
        scanf("%d %d", &moneyToGive, &numberOfFriend);

        for (int j = 0; j < numberOfPeaple; j++)
            if (strcmp(persons[j].name, personName) == 0)
            {
                persons[j].monyRemain = persons[j].monyRemain - moneyToGive;
                if (numberOfFriend == 0)
                    persons[j].monyRemain = persons[j].monyRemain + moneyToGive;
                else
                    persons[j].monyRemain = persons[j].monyRemain + (moneyToGive % numberOfFriend);
            }

        if (moneyToGive == 0 || numberOfFriend == 0)
            continue;
        int moneyToFriend = moneyToGive / numberOfFriend;

        for (int j = 0; j < numberOfFriend; j++)
        {
            char firendName[200];
            scanf("%s", firendName);
            for (int k = 0; k < numberOfPeaple; k++)
                if (strcmp(persons[k].name, firendName) == 0)
                    persons[k].monyRemain = persons[k].monyRemain + moneyToFriend;
        }
    }

    printf("\n");
    for (int i = 0; i < numberOfPeaple; i++)
        printf("%s %d\n", persons[i].name, persons[i].monyRemain);

    return 0;
}
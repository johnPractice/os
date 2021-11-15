
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    // cast malloc to char*
    char *name = (char *)malloc(strlen("Susan") + 1); //reserve the Susan length on malloc
    strcpy(name, "Susan");                            //copy the value to pointer

    while (*name != 0)
    {
        printf("%c\n", *name);
        name++;
    }
    free(name); //free malloc

    return 0;
}
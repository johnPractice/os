#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#define MAX_SIZE 400000
#define STRING_MAX_LEN 100

char *rtrim(char *s)
{
    char *back = s + strlen(s);
    while (isspace(*--back))
        ;
    *(back + 1) = '\0';
    return s;
}

void get_line(char *line, int max)
{
    if (fgets(line, max, stdin) == NULL)
    {

        //  line[strlen(line)-1]='\0';
    }
    rtrim(line);
    // printf("ll %s %s",line,rtrim(line));
}

void assign_separated(char *line, const char *delim, ...)
{

    char *token_ptr = strtok(line, delim);
    va_list ap;
    int j;
    double tot = 0;
    va_start(ap, delim);
    while (token_ptr != NULL)
    {
        *va_arg(ap, int *) = atoi(token_ptr);
        token_ptr = strtok(NULL, delim);
        j += 1;
    }
    va_end(ap);
}

int main()
{

    // printf("%d\n",INT_MAX);
    int n, q, i = 0, num, s, e, qs = -1;
    int *queues;
    long long *cumsum;
    long long int result;
    queues = (int *)malloc(MAX_SIZE * sizeof(int));
    cumsum = (long long int *)malloc(MAX_SIZE * sizeof(int));
    char delim[] = " ";
    char *temp;
    char ch;
    // printf("hi");

    temp = (char *)malloc(STRING_MAX_LEN);
    get_line(temp, STRING_MAX_LEN);
    assign_separated(temp, delim, &n, &q);

    // int queues[n];
    // int cumsum[n];
    for (int j = 0; j < n; j++)
    {
        queues[i] = 0;
        cumsum[i] = 0;
        //  printf("%d\n",queues[i]);
    }
    for (i = 0; i < q; i++)
    {
        char ch = getchar();
        if (ch == '1')
        {
            get_line(temp, STRING_MAX_LEN);
            assign_separated(temp, delim, &num);
            ++qs;
            cumsum[qs + 1] = num + cumsum[qs];
            //   printf("qs:%d\n",qs);
            //   printf("cumsum:%d\n",cumsum[qs+1]);
        }
        else if (ch == '2')
        {
            get_line(temp, STRING_MAX_LEN);
            assign_separated(temp, delim, &s, &e);
            //   printf("s:%d,e:%d\n",s,e);
            if (q - i != 1)
                printf("%Ld\n", (cumsum[queues[s - 1] + e] - cumsum[queues[s - 1]]));
            else
                printf("%Ld", (cumsum[queues[s - 1] + e] - cumsum[queues[s - 1]]));

            queues[s - 1] = queues[s - 1] + e;
        }
    }
}
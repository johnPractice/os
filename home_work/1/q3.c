#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// int main()
// {
//     int sumTotal[100];
//     int pointerToSum = 0;
//     for (int i = 0; i < 100; i++)
//     {
//         sumTotal[i] = 0;
//     }
//     char str[256];
//     fgets(str, 256, stdin);
//     int lenInput = strlen(str);
//     int result[lenInput];
//     for (int i = 0; i < lenInput; i++)
//     {
//         result[i] = 0;
//     }
//     int pointerToResult = 0;
//     int lastResult = 0;
//     for (int i = 0; i < lenInput; i++)
//     {
//         if (str[i] == '{')
//         {
//             result[pointerToResult] = -100;
//             pointerToResult++;
//         }
//         else if (str[i] == '}')
//         {
//             int checkMinus = 0;
//             pointerToResult--;

//             int temp = 0;
//             int check = 0;
//             while (result[pointerToResult] != -100)
//             {
//                 check = 1;
//                 temp = temp + result[pointerToResult];

//                 if (pointerToResult != 0)
//                 {
//                     pointerToResult--;
//                 }

//                 // result[pointerToResult] = temp;
//             }

//             // printf("check the check point %d\n", result[pointerToResult]);
//             // printf("check the befor and afer check point %d %d\n", result[pointerToResult - 1], result[pointerToResult + 1]);
//             // result[pointerToResult] = temp + result[pointerToResult + 1];
//             // printf("hi test 1%d ,%d\n", result[pointerToResult], result[pointerToResult + 1]);
//             // printf("%d\n", result[pointerToResult]);

//             if (check == 0)
//             {
//                 result[pointerToResult] = result[pointerToResult + 1];
//             }
//             else
//             {

//                 result[pointerToResult] = temp;
//             }
//             sumTotal[pointerToResult] = result[pointerToResult];
//             printf("%d\n", result[pointerToResult]);
//         }
//         else
//         {
//             if (str[i] == ' ' || str[i] == ',')
//                 continue;
//             else if (str[i + 1] != ' ' && str[i + 1] != ',' && str[i + 1] != '{' && str[i + 1] != '}')
//             {
//                 int dahgan = (str[i] - '0') * 10;
//                 result[pointerToResult] = (str[i + 1] - '0') + dahgan;
//                 pointerToResult++;
//                 i++;
//             }
//             else
//             {
//                 result[pointerToResult] = str[i] - '0';
//                 // printf("here%d\n", result[pointerToResult]);
//                 pointerToResult++;
//             }
//         }
//     }
//     // for (int i = 0; i < lenInput; i++)
//     // {
//     //     printf("%d\n", result[i]);
//     // }
//     return 0;
// }
// C program for array implementation of stack
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a stack
struct Stack
{
    int top;
    unsigned capacity;
    int *array;
};

// function to create a stack of given capacity. It initializes size of
// stack as 0
struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Stack is full when top is equal to the last index
int isFull(struct Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

// Stack is empty when top is equal to -1
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

// Function to add an item to stack. It increases top by 1
void push(struct Stack *stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
    // printf("%d pushed to stack\n", item);
}

// Function to remove an item from stack. It decreases top by 1
int pop(struct Stack *stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}

// Function to return the top from stack without removing it
int peek(struct Stack *stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}

// Driver program to test above functions
int main()
{

    struct Stack *stack = createStack(100);
    char str[256];
    fgets(str, 256, stdin);
    int lenInput = strlen(str);

    for (int i = 0; i < lenInput; i++)
    {
        if (str[i] == '{')
            push(stack, -100);
        else if (str[i] == '}')
        {

            int temp = 0;
            int popItem = pop(stack);
            int check = 0;
            while (popItem != -100)
            {
                check = 1;
                temp = temp + popItem;
                popItem = pop(stack);
            }
            push(stack, temp);
            printf("%d\n", temp);
        }
        else
        {
            int pushItem;

            if (str[i] == ' ' || str[i] == ',')
                continue;
            else if (str[i + 1] != ' ' && str[i + 1] != ',' && str[i + 1] != '{' && str[i + 1] != '}')
            {
                int hezargan = 0;
                int sadgan = 0;
                int dahgan = 0;
                int yekan = 0;
                if (str[i + 2] != ' ' && str[i + 2] != ',' && str[i + 2] != '{' && str[i + 2] != '}')
                {
                    if (str[i + 3] != ' ' && str[i + 3] != ',' && str[i + 3] != '{' && str[i + 3] != '}')
                    {
                        hezargan = (str[i] - '0') * 1000;
                        sadgan = (str[i + 1] - '0') * 100;
                        dahgan = (str[i + 2] - '0') * 10;
                        yekan = str[i + 3] - '0';
                        i = i + 3;
                    }
                    else
                    {
                        sadgan = (str[i] - '0') * 100;
                        dahgan = (str[i + 1] - '0') * 10;
                        yekan = str[i + 2] - '0';
                        i = i + 2;
                    }
                }
                else
                {
                    dahgan = (str[i] - '0') * 10;
                    yekan = (str[i + 1] - '0');
                    i++;
                }
                pushItem = hezargan + sadgan + dahgan + yekan;
            }
            else
            {
                pushItem = str[i] - '0';
            }
            // printf("pushed item is %d\n", pushItem);
            push(stack, pushItem);
        }
    }

    // push(stack, 10);
    // push(stack, 20);
    // push(stack, 30);

    // printf("%d popped from stack\n", pop(stack));

    return 0;
}

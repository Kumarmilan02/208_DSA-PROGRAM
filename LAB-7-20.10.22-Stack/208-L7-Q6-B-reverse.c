// WAP TO REVERSE A STACK 
/*==METHOD-"02"== **/

#include <stdio.h>
#include <stdlib.h>
void push(int *arr, int *N, int *t)
{
    if (*t == (*N) - 1)
    {
        printf("\n OVERFLOW.");
        return;
    }
    *t = *t + 1;
    printf("\n ENTER ELEMENT: ");
    scanf("%d", &arr[*t]);
    return;
}
int pop(int *arr, int *N, int *t)
{
    if (*t == -1)
    {
        printf("\n UNDERFLOW.");
        return 0;
    }
    printf("\n TOP: %d", *t);
    int itm = arr[*t];
    *t = *t - 1;
    return itm;
}

void display(int *arr, int *t)
{
    if (*t == -1)
    {
        printf("\n NO ELEMENTS.");
        return;
    }
    printf("\n STACK: ");
    for (int i = 0; i <= *t; i++)
    {
        printf(" %d| ", arr[i]);
    }
    return;
}
int *reverse(int *arr, int *N, int *t)
{
    int *temp = (int *)malloc((*N) * (sizeof(int)));
    int i = 0;
    int top2 = *t;
    while (top2 >= 0)
    {
        temp[i] = pop(arr, N, &top2);
        i++;
    }
    arr = temp;
    display(arr, t);
    return temp;
}
int main()
{
    int *stack;
    int top = -1;
    int n;
    printf("\n ENTER LIMIT OF STACK: ");
    scanf("%d", &n);
    stack = (int *)malloc(n * (sizeof(int)));
    int ch = 1;
    while (ch != 5)
    {
        printf("\n==STACK==\n");
        printf("\n1.PUSH.");
        printf("\n2.POP.");
        printf("\n3.DISPLAY.");
        printf("\n4.REVERSE.");
        printf("\n5.EXIT");
        printf("\n\nENTER CHOICE: ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            char c = 'Y';
            while ((c == 'y') || (c == 'Y'))
            {
                printf("\n PUSHING\n");
                push(stack, &n, &top);
                printf("\n DO YOU WANT TO CONTINUE? ");
                scanf(" %c", &c);
            }
            continue;
        }
        else if (ch == 2)
        {
            printf("ITEM POPPED: %d", pop(stack, &n, &top));
            continue;
        }
        else if (ch == 3)
        {
            display(stack, &top);
            continue;
        }
        else if (ch == 4)
        {
            stack = reverse(stack, &n, &top);
            continue;
        }
    }
    return 0;
}
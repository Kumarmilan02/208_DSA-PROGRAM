// WAP TO IMPLEMENT QUEUE USING TWO STACK.

#include "stdio.h"
int stack1[5], stack2[5];
int i = -1, j = -1;
void push(int num)
{
    i++;
    stack1[i] = num;
}
int pop()
{
    while (i >= 0)
    {
        j++;
        stack2[j] = stack1[i];
        i--;
    }
    int k = stack2[j];
    j--;
    while (j >= 0)
    {
        i++;
        stack1[i] = stack2[j];
        j--;
    }
    return k;
}
void display()
{
    int k;
    if (i == -1)
    {
        printf("\nQueue is Empty.");
    }
    else
    {
        printf("\nQueue element is: ");
        for (k = 0; k <= i; k++)
        {
            printf("%d |", stack1[k]);
        }
    }
    printf("\n");
}
int main()
{
    int n, num;
    do
    {
        printf("\n");
        printf("\n1.insert");
        printf("\n2.delete");
        printf("\n3.display");
        printf("\n0.stop");
        printf("\nChoice: ");
        scanf("%d", &n);
        if (n == 1)
        {
            if (i >= 4)
            {
                printf("\nQueue is full");
                continue;
            }
            printf("\nEnter data to insert: ");
            scanf("%d", &num);
            push(num);
        }
        else if (n == 2)
        {
            if (i == -1)
            {
                printf("\nQueue is empty.");
                continue;
            }
            num = pop();
            printf("\nPOPPED: %d", num);
        }
        else if (n == 3)
        {
            display();
        }
        else
        {
            printf("\nInvalid choice.");
        }
    } while (n != 0);
    return 0;
}
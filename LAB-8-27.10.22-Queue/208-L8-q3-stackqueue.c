/*WAP TO IMPLEMENT STACK USING TWO QUEUE*/

#include <stdio.h>
#include <stdlib.h>

#define size 10
int que1[size];
int que2[size];
int f1 = -1, r1 = -1, f2 = -1, r2 = -1;
int count = 0;

void enqueue1(int c)
{
    if (r1 == size - 1 && f1 == 0)
    {
        printf("\nOVERLFOW.");
        return;1
    }
    if (f1 == -1 && r1 == -1)
    {
        f1 = 0;
        r1 = 0;
    }
    else
    {
        r1 = r1 + 1;
    }
    que1[r1] = c;
    return;
}
void enqueue2(int c)
{
    if (r2 == size - 1 && f2 == 0)
    {
        printf("\nOVERLFOW.");
        return;
    }
    if (f2 == -1 && r2 == -1)
    {
        f2 = 0;
        r2 = 0;
    }
    else
    {
        r2 = r2 + 1;
    }
    que2[r2] = c;
    return;
}
int dequeue1()
{
    if (f1 == -1)
    {
        printf("\nUNDERFLOW.");
        return 0;
    }
    int item = que1[f1];
    if (f1 == r1)
    {
        f1 = -1;
        r1 = -1;
    }
    else
    {
        f1 = f1 + 1;
    }
    return item;
}
int dequeue2()
{
    if (f2 == -1)
    {
        printf("\nUNDERFLOW.");
        return 0;
    }
    int item = que2[f2];
    if (f2 == r2)
    {
        f2 = -1;
        r2 = -1;
    }
    else
    {
        f2 = f2 + 1;
    }
    return item;
}
void push(int c)
{
    enqueue1(c);
    count++;
    if (count > size)
    {
        count--;
    }
}
void pop()
{
    int i;
    for (i = 0; i < count - 1; i++)
    {
        int temp = dequeue1();
        enqueue2(temp);
    }
    int item = dequeue1();
    printf("\n ITEM POPPED: %d", item);
    count--;
    for (i = 0; i < count; i++)
    {
        int temp = dequeue2();
        enqueue1(temp);
    }
}
void display()
{
    printf("\nQUEUE:");
    if (f1 == -1)
    {
        printf(" NO ELEMENTS.");
        return;
    }
    for (int i = f1; i <= r1; i++)
    {
        printf("%d| ", que1[i]);
    }
    return;
}
int main()
{
    int ch = 1;
    while (ch != 4)
    {
        printf("\n  STACK USING QUEUES: ");
        printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT");
        printf("\n ENTER CHOICE: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            int n;
            printf("\n ENTER ELEMENT: ");
            scanf("%d", &n);
            push(n);
        }
        break;
        case 2:
        {
            pop();
        }
        break;
        case 3:
        {
            display();
        }
        break;
        }
    }
    return 0;
}

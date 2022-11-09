/*WAP TO REVERSE FIRST K DIGIT OF QUEUE.*/
/*METHOD:2 **/


#include <stdio.h>
#include <stdlib.h>

#define size 10
int que1[size];
int stack1[size];
int f1 = -1, r1 = -1, t1 = -1;
int count;
void enqueue1(int c)
{
    if (r1 == size - 1 && f1 == 0)
    {
        printf("\nOVERLFOW.");
        return;
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
void push1(int c)
{
    if (t1 >= size - 1)
    {
        printf("\n OVERFLOW.");
        return;
    }
    t1++;
    stack1[t1] = c;
    return;
}
int pop1()
{
    if (t1 == -1)
    {
        printf("\n UNDERFLOW.");
        return 0;
    }
    int item = stack1[t1];
    t1--;
    return item;
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
void revk(int k)
{
    int i;
    for (i = 0; i < k; i++)
    {
        push1(dequeue1());
    }
    for (i = 0; i < k; i++)
    {
        enqueue1(pop1());
    }
    for (i = 0; i < count - k; i++)
    {
        enqueue1(dequeue1());
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
    while (ch != 5)
    {
        printf("\n");
        printf("\n  STACK USING QUEUES: ");
        printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.REVERSE FIRST K\n5.EXIT");
        printf("\n ENTER CHOICE: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            int n;
            printf("\n ENTER ELEMENT: ");
            scanf("%d", &n);
            enqueue1(n);
            count++;
            if (count > size)
            {
                count = size;
            }
        }

        break;
        case 2:
        {
            int itm;
            itm = dequeue1();
            printf("\n DEQUEUED ELEMENT: %d", itm);
            count--;
            if (count <= 0)
            {
                count = 0;
            }
        }
        break;
        case 3:
        {
            display();
        }
        break;
        case 4:
        {
            int k;
            printf("\n ENTER K TO REVERSE: ");
            scanf("%d", &k);
            revk(k);
            display();
        }
        break;
        }
    }
    return 0;
}
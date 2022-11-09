/*WAP TO REVERSE FIRST K DIGIT OF QUEUE.*/
/*METHOD:1*/

#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

int isfull()
{
    int f = 0;
    if (rear == MAX - 1)
    {
        f = 1;
    }
    return f;
}

int isempty()
{
    int f = 0;
    if (front > rear)
    {
        f = 1;
    }

    if (front == -1 && rear == -1)
    {
        f = 1;
    }
    return f;
}

void push(int x)
{
    if (isfull())
    {
        printf("Overflow\n");
    }
    else
    {
        if (front == -1)
        {
            front=rear=0;
        }
        queue[rear] = x;
        rear++;
    }
}

int pop()
{
    if (isempty())
    {
        printf("Underflow\n");
    }
    else
    {
        int s = queue[front];
        front++;
        return s;
    }
}

void push_front(int d)
{
    if (front == -1)
    {
        printf("Overflow\n");
    }
    else
    {
        front--;
        queue[front] = d;
    }
}

void display()
{
    for (int i = front; i <= rear; i++)
    {
        printf("%d\t", queue[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the number of digits:\n");
    scanf("%d", &n);

    int w;
    for (int i = 0; i < n; i++)
    {
        printf("Enter the element to insert:\n");
        scanf("%d", &w);

        push(w);
    }
    printf("\nDISPLAY: ");
    display();
    int k;
    printf("\nEnter the value of k:\n");
    scanf("%d", &k);

    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum = 100 * (sum) + pop();
    }

    int dig;
    int s1 = 0;

    while (sum > 0)
    {
        dig = sum % 100;
        s1 = 100 * (s1) + dig;
        sum = sum / 100;
    }

    int last;

    while (s1 > 0)
    {
        last = s1 % 100;
        push_front(last);
        s1 = s1 / 100;
    }
    printf("\nREVERSE QUEUE FROM FIRST %d DIGIT: ",k);
    display();
    return 0;
}
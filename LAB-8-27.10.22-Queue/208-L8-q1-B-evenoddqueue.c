/*WAP TO IMPLEMENT A QUEUE WITH (i)LET THERE ARE 2 FIXED SIZE ARRAYS USED FOR IMPLEMENTATION OF QUEUE.*/
/*ONE ARRAY IS USED FOR EVEN AND OTHER IS USED FOR ODD ELEMENT.*/
/*(ii)INSERTION: IF EVEN ELEMENT IS COMES, AN EVEN ELEMENT ARRAY IS NOT FULL THEN ADD ELEMENT IN REAR END OF EVEN QUEUE.*/
/*IF AN EVEN ELEMENT COME AND EVEN ARRAY IS FULL THEN ADD ELEMENT IN ODD ARRAY.*/
/*DELETE: DELETE FRONT ELEMENT OF ARRAY HAVING MAXIMUM NO OF ELEMENT IN ARRAY*/
/*METHOD:-"02"-*/

#include <stdio.h>
#include <stdlib.h>

int flag = 0;
void enqueue(int no, int *arr, int *N, int *t, int *r)
{
    if (flag >= 1)
    {
        flag = 0;
    }
    printf("\n%d", *r);
    if (*r == (*N) - 1)
    {
        printf("\nOVERLFOW.");
        return;
    }
    if (*t == -1 && *r == -1)
    {
        *t = 0;
        *r = 0;
    }
    else
    {
        *r = *r + 1;
    }
    arr[*r] = no;
    return;
}
void display(int *arr1, int *arr2, int *N, int *t1, int *t2, int *r1, int *r2)
{
    printf("\nQUEUE1(EVEN):");
    if (flag >= 1)
    {
        printf("\n NO ELEMENTS");
    }
    else
    {
        for (int i = (*t1); i <= (*r1); i++)
        {
            printf("%d| ", arr1[i]);
        }
    }
    printf("\n QUEUE2(ODD): ");
    if (flag >= 2)
    {
        printf("\n NO ELEMENTS.");
    }
    else
    {
        for (int i = (*t2); i <= (*r2); i++)
        {
            printf("%d| ", arr2[i]);
        }
    }
    return;
}
void dequeue(int *arr, int *t, int *r)
{
    if (*t == -1 || flag == 2)
    {
        printf("\nUNDERFLOW.");
        return;
    }
    int item = arr[*t];
    if (*t == *r)
    {
        *t = -1;
        *r = -1;
        flag += 1;
    }
    else
    {
        *t = *t + 1;
    }
    printf("\nTOP|REAR: %d|%d", *t, *r);
    printf("\nITEM DEQUEUED: %d", item);
    return;
}

int main()
{
    int n;
    printf("\n ENTER THE MAX LIMIT OF QUEUE: ");
    scanf("%d", &n);
    int *queue1, *queue2;
    int top1 = (-1), rear1 = (-1), rear2 = (-1), top2 = (-1);
    queue1 = (int *)malloc(n * sizeof(int));
    queue2 = (int *)malloc(n * sizeof(int));
    int ch = 1;
    while (ch != 4)
    {
        printf("\n==QUEUE==\n");
        printf("\n1.ENQUEUE.");
        printf("\n2.DEQUEUE.");
        printf("\n3.DISPLAY.");
        printf("\n4.EXIT");
        printf("\n\nENTER CHOICE: ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            int y = 1;
            while (y == 1)
            {
                int en;
                printf("\n ENTER ELEMENT: ");
                scanf("%d", &en);
                if (en % 2 == 0)
                {
                    if (rear1 <= n - 2)
                    {
                        enqueue(en, queue1, &n, &top1, &rear1);
                    }
                    else if (rear1 >= n - 1)
                    {
                        enqueue(en, queue2, &n, &top2, &rear2);
                    }
                }
                else
                {
                    enqueue(en, queue2, &n, &top2, &rear2);
                }
                printf("\n1 TO CONITNUE: ");
                scanf("%d", &y);
            }
        }
        else if (ch == 2)
        {
            if (((rear1 - top1) >= (rear2 - top2)) && flag != 1)
            {
                dequeue(queue1, &top1, &rear1);
            }
            else
            {
                dequeue(queue2, &top2, &rear2);
            }
        }
        else if (ch == 3)
        {
            display(queue1, queue2, &n, &top1, &top2, &rear1, &rear2);
            continue;
        }
    }
    return 0;
}
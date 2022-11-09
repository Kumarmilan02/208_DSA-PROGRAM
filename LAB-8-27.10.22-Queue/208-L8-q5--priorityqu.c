/*WAP TO IMPLEMENT PRIORITY QUEUE USING LINKLIST*/

#include"stdio.h"
#include"stdlib.h"
#pragma pack(1)
struct queue
{
    int data;
    struct queue *link;
};
struct queue *f=0,*r=0,*q,*m;
void enqueue(int num)
{
    if(r==0)
    {
        r=(struct queue *)malloc(sizeof(struct queue));
        f==r;
        r->data=num;
        r->link=0;
    }
    else if(num <= r->data)
    {
        q=(struct queue *)malloc(sizeof(struct queue));
        q->data=num;
        q->link=r;
        r=q;
        f=q;
    }
    else
    {
        while(r!=0 && num > r->data)
        {
            m=r;
            r=r->link;
        }
        q=(struct queue *)malloc(sizeof(struct queue));
        q->data=num;
        m->link=q;
        q->link=r;
        r=f;
    }
} 
int dequeue()
{
    int k=f->data;
    r=f->link;
    free(f);
    f=r;
    return k;
}
void display()
{
    q=f;
    while(q->link!=0)
    {
        printf("%d-->",q->data);
        q=q->link;
    }
    printf("%d-->NULL",q->data);
}
int main()
{
    int n, num;
    do
    {
        printf("\n");
        printf("\n1.ENQUEUE");
        printf("\n2.DEQUEUE");
        printf("\n3.DISPLAY");
        printf("\n0.STOP");
        printf("\nChoice: ");
        scanf("%d", &n);
        if (n == 1)
        {
            printf("\nEnter data to insert: ");
            scanf("%d", &num);
            enqueue(num);
        }
        else if (n == 2)
        {
            if (f == 0)
            {
                r=0;
                printf("\nQueue is empty.");
                continue;
            }
            num = dequeue();
            printf("\nDELETE: %d", num);
        }
        else if(n == 3)
        {
            display();
        }
        else
        {
            printf("\nInvalid choice.");
        }
    }while(n!=0);
    return 0;
}
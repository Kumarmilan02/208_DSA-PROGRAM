//Create enqueue and dequeue operation using linklist.
#include"stdio.h"
#include"stdlib.h"
struct queue
{
    int data;
    struct queue *next;
};
struct queue *f=0,*r=0;
void enqueue(int);
int dequeue();
void traverse();
int main()
{
    int n,num;
    do
    {
        printf("\n");
        printf("\n1.ENQUEUE");
        printf("\n2.DEQUEUE");
        printf("\n3.TRAVERSE");
        printf("\n0.STOP");
        printf("\nENTER UR CHOICE: ");
        scanf("%d",&n);
        if(n==1)
        {
            printf("\nEnter data to insert: ");
            scanf("%d",&num);
            enqueue(num);
        }
        else if(n==2)
        {
            if(f==0)
            {
                r=0;
                printf("\nQUEUE IS UNDERFLOW.");
                continue;
            }
            num=dequeue();
            printf("DELETE: %d",num);
        }
        else if(n==3)
        {
            traverse();
        }
    }while(n!=0);
}
void traverse()
{
    struct queue *q=f;
    printf("\nThe Queue is: \n");
    while(q!=0)
    {
        printf("%d->",q->data);
        q=q->next;
    }
}
void enqueue(int num)
{
    struct queue *q;
    if(f==0 && r==0)
    {
        r=(struct queue *)malloc(sizeof(struct queue));
        r->data=num;
        r->next=0;
        f=r;
    }
    else
    {
        q=(struct queue *)malloc(sizeof(struct queue));
        q->data=num;
        q->next=0;
        r->next=q;
        r=q;
    }
}
int dequeue()
{
    struct queue *q;
    int k;
    k=f->data;
    q=f->next;
    free(f);
    f=q;
    return k;
}
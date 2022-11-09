//CREATE CIRCULAR QUEUE USING DYNAMIC ARRAY.

#include"stdio.h"
#include"stdlib.h"
struct queue
{
    int f,r,max;
    int *arr;
};  
struct queue *createque(int m)
{
    struct queue *p=(struct queue *)malloc(sizeof(struct queue));
    p->r=p->f=-1;
    p->max=m;
    p->arr=(int *)malloc(sizeof(int)*p->max);
    return p;
} 
void showqueue(struct queue *q)
{
    printf("\nfront = %d, Rear= %d, size= %d",q->f,q->r,q->max);
}   
void enqueue(struct queue *q,int m)
{
    if((q->r==m-1 && q->f==0) || (q->r+1==q->f))
    {
        printf("\nQUEUE IS FULL.\n");
        showqueue(q);
        return;
    }
    if(q->r==m-1)
        q->r=0;
    else
        (q->r)++;
    int val;
    printf("\nENTER DATA: ");
    scanf("%d",&val);
    q->arr[q->r]=val;
    if(q->f==-1)
        q->f=0;
    printf("\nEnqueued.");
}
int dequeue(struct queue *q)
{
    if(q->f==-1)
    {
        printf("\nUNDERFLOW.");
        showqueue(q);
        return NULL;
    }
    int val=q->arr[q->f];
    q->arr[q->f]=0;
    if(q->f==q->r)
    {
        q->f=(-1);
        q->r=(-1);
    }
    else
    {
        if(q->f==((q->f)+1)%(q->max))
            q->f=0;
        else
            (q->f)++;
    }
    printf("\nDEQUEUED: %d",val);
    showqueue(q);
    return;
}
void display(struct queue *q)
{
     if(q->f==-1 && q->r==-1)
    {
        printf("\nQueue is Empty.");
    }
    else
    {
        int i;
        for(i=0;i<q->max;i++)
        {
            printf("%d \t",q->arr[i]);
        }
        printf("\n");
    }
}
int main()
{
    int n;
    printf("\n ENTER QUEUE SIZE: ");
    scanf("%d",&n);
    struct queue *s=NULL;
    s=createque(n);
    int num=1;
    while(num!=5)
    {
        printf("\n==QUEUE==");
        printf("\n1.ENQUEUE.");
        printf("\n2.DEQUEUE.");
        printf("\n3.DISPLAY.");
        printf("\n4.STATAUS");
        printf("\n5.EXIT");
        printf("\n\nENTER CHOICE: ");
        scanf("%d",&num);
        if(num==1)
        {
            enqueue(s,n);
            continue;
        }
        else if(num==2)
        {
            dequeue(s);
            continue;
        }
        else if(num==3)
        {
            display(s);
            continue;
        }
        else if(num==4)
        {
            showqueue(s);
            continue;
        }
        else if(num==5)
        {
            exit(0);
        }
    }
    return 0;
}
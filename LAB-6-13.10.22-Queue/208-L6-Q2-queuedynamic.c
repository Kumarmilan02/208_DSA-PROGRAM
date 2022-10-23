//Create enqueue and dequeue operation using dynamic array.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void enqueue(int* arr,int* N,int* f,int* r)
{
    if(*r==(*N)-1)
    {
        printf("\nOVERLFOW.");
        return;
    }
    if(*f==-1&&*r==-1)
    {
        *f=0;
        *r=0;
    }
    else{
        *r=*r+1;
    }
    printf("\nENTER DATA: ");
    scanf("%d",&arr[*r]);
    return;
}
void display(int* arr,int* N,int* f)
{
    printf("\nQUEUE:");
    for(int i=(*f);i<(*N);i++)
    {
        printf("%d-> ",arr[i]);
    }
    return;
}
void dequeue(int* arr,int* f,int* r)
{
    if(*f==-1)
    {
        printf("\nUNDERFLOW.");
        return;
    }
    int item=arr[*f];
    if(*f==*r)
    {
        *f=0;
        *r=0;
    }
    else
    {
        *f=*f+1;
    }
    printf("\nITEM DEQUEUED: %d",item);
    return;
}

int main()
{
    int n;
    printf("\n ENTER QUEUE SIZE: ");
    scanf("%d",&n);
    int *queue;
    int front=(-1),rear=(-1);
    queue=(int*)malloc(n*sizeof(int));
    int num=1;
    char x[5];
    while(num!=4)
    {
        printf("\n==QUEUE==\n");
        printf("\n1.ENQUEUE.");
        printf("\n2.DEQUEUE.");
        printf("\n3.DISPLAY.");
        printf("\n4.EXIT");
        printf("\n\nENTER CHOICE: ");
        scanf("%d",&num);
        if(num==1)
        {
            {
                printf("\n ENQUEUING\n");
                enqueue(queue,&n,&front,&rear);
                printf("\n DO YOU WANT TO CONTINUE YES/NO: ");
                scanf("%s",x);
                if (strcmp(x,"no")==0)
                    break;
            }
            continue;}
        else if(num==2)
        {
            dequeue(queue,&front,&rear);
            continue;
        }
        else if(num==3)
        {
            display(queue,&n,&front);
            continue;
        }
        else if(num==4)
        {
            exit(0);
        }
    }
    return 0;


}
    

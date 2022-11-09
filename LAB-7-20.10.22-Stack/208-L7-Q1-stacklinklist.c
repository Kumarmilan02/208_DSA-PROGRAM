//WAP TO IMPLEMENT PUSH AND POP OPERATION USING LINKLIST.

#include<stdio.h>
#include<stdlib.h>
void push(int);
int pop();
void display();
struct stack
{
    int data;
    struct stack * next;
};
struct stack *s=0,*q;
int main()
{
    int n;
    int data;
    do {
        printf("\n==STACK==");
        printf("\n1.PUSH");
        printf("\n2.POP");
        printf("\n3.DISPLAY");
        printf("\n0.STOP");
        printf("\nENTER  UR CHOICE: ");
        scanf("%d",&n);
        if (n == 1)
        {
            printf("ENTER THE DATA TO BE PUSH: \n");
            scanf("%d", &data);
            push(data);
        }
        else if (n == 2)
        {
            if (s==0)
            {
                printf("STACK IS EMPTY\n");
                continue;
            }
            data = pop();
            printf("popped: %d", data);
        }
        else if(n==3)
        {
            display();
        }
    }while(n!=0);
}

void push(int data)
{
    if(s==0)
    {
        s=(struct stack *)malloc(sizeof(struct stack));
        s->data=data;
        s->next=0;
    }
    else
    {
        q=(struct stack *)malloc (sizeof(struct stack));
        q->next=s;
        s=q;
        q->data=data;
    }
}

int pop()
{
    int k=s->data;
    q=s->next;
    free(s);
    s=q;
    return  k;
}

void display()
{
    struct stack *q=s;
    while (q->next != 0)
    {
        printf("%d->", q->data);
        q = q->next;
    }
    printf("%d->NULL",q->data);
    printf("\n");
}
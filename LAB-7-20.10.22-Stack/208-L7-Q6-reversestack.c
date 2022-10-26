///WAP TO IMPLEMENT PUSH AND POP OPERATION USING LINKLIST IN STACK.

#include"stdio.h"
#include"string.h"
#include"stdlib.h"
struct node
{
    int data;
    struct node *next;
};
struct node *p=0,*q;
void push(struct node *);
struct node pop();
void display(struct node);
//void reversestack(struct node *);
int main()
{
    int n;
    struct node *m;
    do
    {
        printf("\n==STACK==");
        printf("\n 1-Push");
        printf("\n 2-Pop");
        printf("\n 3-Display");
        printf("\n 4.Reverse");
        printf("\n 0-Stop");
        printf("\nEnter ur choice: ");
        scanf("%d",&n);
        if(n==1)
        {
            printf("\nEnter Data: ");
            scanf("%d",&m->data);
            printf("\nPUSHING");
            push(m);
        }
        else if(n==2)
        {
            if(p==NULL)
            {
                printf("Stack Underflow.");
                    continue;
            }
            m=pop();
            printf("POP: %d",m->data);
        }
        else if(n==3)
        {
            printf("\nSTACK DISPLAY.");
            display(m);
        }
        else if(n==4)
        {
            //reversestack(&);
            display(m);
        }
    }while(n!=0);
    return 0;
}
void push(struct node *m)
{
    if(p==0)
    {
        p=(struct node *)malloc(sizeof(struct node));
        p->data=m->data;
        p->next=0;
    }
    else
    {
        q=(struct node *)malloc(sizeof(struct node ));
        q->next=p;
        p=q;
        p->data=m->data;
    }
}
struct node pop()
{
    struct node m;
    m->data=p->data;
    q=p->next;
    free(p);
    p=q;
    return m;
}
void display(struct node m)
{
    if(p==NULL)
    {
        printf("Stack is Empty.");
        return;
    }
    else
    {
        struct node *q=p;
        while(q->next!=NULL)
        {
            printf("%d-->",q->data);
            q=q->next;
        }
        printf("%d-->NULL",q->data);
    }
}

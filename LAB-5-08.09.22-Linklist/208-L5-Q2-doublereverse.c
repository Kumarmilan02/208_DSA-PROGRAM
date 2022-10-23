////WAP TO REVERSE NODE OF A DOUBLE LINKLIST

#include"stdio.h"
#include"stdlib.h"
#include"string.h"
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
void traverse_ltor(struct node *);
void createlinklist();
struct node *reverse();
struct node *b1,*b2;//b1=1st base addres of pointer and b2=last base address of pointer
int main()
{
    createlinklist();
    printf("\nLINKLIST IN LEFT TO RIGHT ORDER\n");
    traverse_ltor(b1);
    printf("\n");
    printf("\nREVERSE DOUBLE LINKLIST\n");
    b1=reverse(b1);
    traverse_ltor(b1);
}
void traverse_ltor(struct node *p)
{
    while(p!=NULL)
    {
        printf("%d<=====>",p->data);
        p=p->next;
    }
}
void createlinklist()
{
    struct node *p,*q,*head;
    char x[5];
    p=(struct node *)malloc(sizeof(struct node));
    p->prev=NULL;
    head=p;
    printf("Enter data: ");
    scanf("%d",&p->data);
    while(1)
    {
        printf("DO U CONTINUE yes/no: ");
        scanf("%s",x);
        if(strcmp(x,"no")==0)
            break;
        q=(struct node *)malloc(sizeof(struct node));
        p->next=q;
        q->prev=p;
        p=q;
        printf("Enter data: ");
        scanf("%d",&p->data);
    }
    p->next=0;
    b1=head;
}
struct node *reverse(struct node *head)
{
    struct node *ptr1=head;
    struct node *ptr2=ptr1->next;
    ptr1->next=NULL;
    ptr1->prev=ptr2;//update the link of the 1st node only
    while(ptr2!=NULL)//update the link of other node
    {
        ptr2->prev=ptr2->next;
        ptr2->next=ptr1;
        ptr1=ptr2;
        ptr2=ptr2->prev;
    }
    head=ptr1;//refer to last node of the link
    return head;
}


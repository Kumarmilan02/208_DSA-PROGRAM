//WAP TO REVERSE NODE OF A SINGLE LINKLIST

#include"string.h"
#include"stdio.h"
#include"stdlib.h"
#pragma pack(1) //remove slack byte(wastage of memory)
struct node
{
        int data;
        struct node *next;
};
struct node *createlinklist();
struct node *reverse();
int traverse(struct node *);
int main()
{
        struct node *b;
        b=createlinklist();
        printf("\nThe linklist is: \n");
        traverse(b);
        printf("\nThe reverse of linklist is: \n");
        b=reverse(b);
        traverse(b);
}
struct node *createlinklist()
{
        struct node *p,*q,*head;
        char x[5];
        p=(struct node *)malloc(sizeof(struct node));
        head=p;  //temp refers first block
        printf("Enter data: ");
        scanf("%d",&p->data);
        while(1)
        {
            printf("Do you continue yes/no");
            scanf("%s",x);
            if (strcmp(x,"no")==0)
                break;
            q=(struct node *)malloc(sizeof(struct node));
            p->next=q; //joint p&q
            p=q; // p is shifted to q position
            printf("Enter data: ");
            scanf("%d",&p->data);
        }
        p->next=0; //last node of linklist
        return head; //return base address of linklist
}
int traverse(struct node *m)
{
    struct node *temp=m;
    while(temp!=NULL)
    {
        printf("%d-->",temp->data);
        temp=temp->next;
    }  
}
struct node *reverse(struct node *r)
{
    struct node *prev=NULL;
    struct node *head=r;
    struct node *current;

    while(head!=NULL)
    {
        current=head->next;
        head->next=prev;
        prev=head;
        head=current;
    }
    return prev;
}


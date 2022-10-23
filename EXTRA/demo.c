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
        struct node *b,*b1;
        b=createlinklist();
        printf("\nThe linklist is: \n");
        traverse(b);
        printf("\nThe reverse of linklist is: \n");
        b1=reverse(b);
        traverse(b1);
        if(b==b1)
        {
            printf("\nPalindrome Linked List\n");
        } 
        else 
        {
            printf("\nNot a Palindrome Linked List\n");
        }
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
int compareLinkedList(struct node* LLOne, struct node* LLTwo){ 
    while (LLOne != NULL && LLTwo != NULL) {
        if (LLOne->data != LLTwo->data)
            return 0;
        LLOne = LLOne->next;
        LLTwo = LLTwo->next;
    }
    return (LLOne == NULL && LLTwo == NULL);
}



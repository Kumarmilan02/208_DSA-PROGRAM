//WAP to create a linklist.

#include"string.h"
#include"stdio.h"
#include"stdlib.h"
struct student
{
        int roll;
        char name[20];
        struct student *next;
};
struct student *createlinklist();
int main()
{
        struct student *b;
        b=createlinklist();
}
struct student *createlinklist()
{
        struct student *p,*q,*temp;
        char x[5];
        p=(struct student *)malloc(sizeof(struct student));
        temp=p;  //temp refers first block
        printf("Enter roll: ");
        scanf("%d",&p->roll);
        printf("Enter name: ");
        scanf("%s",p->name);
        while(1)
        {
                printf("Do you continue yes/no");
                scanf("%s",x);
                if (strcmp(x,"no")==0)
                        break;
                q=(struct student *)malloc(sizeof(struct student));
                p->next=q; //joint p&q
                p=q; // p is shifted to q position
                printf("Enter roll: ");
                scanf("%d",&p->roll);
                printf("Enter name: ");
                scanf("%s",p->name);

        }
        p->next=0; //last node of linklist
        return temp; //return base address of linklist
}


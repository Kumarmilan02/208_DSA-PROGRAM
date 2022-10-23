#include"stdio.h"
#include"stdlib.h"
#include"string.h"
struct student
{
    int roll;
    char name[20];
    struct student *next;
};
struct student *createcircular();
void traverse(struct student *);
struct student *insertnode(struct student*,int);
struct student *deletenode(struct student*,int);
int main()
{
    struct student *b;
    int n,pos;
    while(n!=4){
    printf("\n1.createcircularlinklist \n2.insertnode \n3.deletenode \n4.Exit");
    printf("\nEnter choice: ");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
            b=createcircular();
            printf("\nDISPLAY\n");
            traverse(b);
            break;
        case 2:
            printf("\nEnter position to insert: ");
            scanf("%d",&pos);
            b=insertnode(b,pos);
            printf("\nDISPLAY\n");
            traverse(b);
            break;
        case 3:
            printf("\nEnter position to delete: ");
            scanf("%d",&pos);
            b=deletenode(b,pos);
            printf("\nDISPLAY\n");
            traverse(b);
            break;
        case 4:
            printf("EXIT");
            break;
        default:
            printf("invalid option.");
    }
    }
    return 0;

}
struct student *createcircular()
{
        struct student *p,*q,*temp;
        char x[5];
        p=(struct student *)malloc(sizeof(struct student)); //create a linklist.
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
        p->next=temp; //last node of linklist
        return temp; //return base address of linklist
}
void traverse(struct student *p)
{
    struct student *q=p;
    while(p->next!=q)
    {
        printf("%d %s\n",p->roll,p->name);
        p=p->next;
    }
    printf("%d %s\n",p->roll,p->name);
}
struct student *insertnode(struct student *p,int pos)
{
        struct student *q,*m,*old=p;
        int i;
        if(pos==1)
        {
                q=(struct student *)malloc(sizeof(struct student));
                q->next=p;
                printf("Enter roll: ");
                scanf("%d",&q->roll);
                printf("Enter name: ");
                scanf("%s",q->name);
                return q;
        }
        else
        {
                for(i=1;i<pos;i++)
                {
                        m=p;
                        p=p->next;
                }
                q=(struct student *)malloc(sizeof(struct student));
                q->next=p;
                printf("Enter roll: ");
                scanf("%d",&q->roll);
                printf("Enter name: ");
                scanf("%s",q->name);
                m->next=q;
                q->next=p;
                return old;

        }
}
struct student *deletenode(struct student *p,int pos)
{
        struct student *q,*m,*old=p;
        int i;
        if(pos==1)
        {
                q=p->next;
                free(p);
                return q;
        }
        else
        {
                for(i=1;i<pos;i++)
                {
                        m=p;
                        p=p->next;
                }
                m->next=p->next;
                free(p);
                return old;

        }
}

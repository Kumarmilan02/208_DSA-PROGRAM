//multiply two polynomia

#include "stdio.h"
#include "stdlib.h" 
#include "string.h"
struct poly
{
    int cof;
    int exp;
    struct poly *next;
};
struct poly *createlinklist(); 
void traverse(struct poly *);
struct poly *multiplye(struct poly *p, struct poly *q);
int checklinklist(struct poly t, struct poly *p);
int main()
{
    struct poly *basel=0, *base2=0, *base3; 
    printf("1st polynomial");
    basel=createlinklist();
    traverse(basel);
    printf("\n");            
    
    printf("\n2nd POLYNOMIAL");
    base2=createlinklist();
    traverse(base2);
    printf("\n");

    printf("\nMULTIPLICATION\n");
    base3=multiplye(basel,base2);
    traverse(base3);
    printf("\nend");
    return 0;
}

struct poly *multiplye(struct poly *p,struct poly *q)
{
    struct poly *a=0,*b,*temp;
    struct poly *m=q,t;
    int status;
    while(p!=0)
    {
        q=m;
        while(q!= 0)
        {
            if(a==0)
            {
                a=(struct poly *)malloc(sizeof(struct poly));
                temp=a;
                a->cof=p->cof * q->cof; 
                a->exp=p->exp + q->exp;
            }
            else
            {
                t.cof=p->cof * q->cof; 
                t.exp=p->exp + q->exp;
                status=checklinklist(t,temp); //0 not present
                if(status==0)
                {
                    b=(struct poly *)malloc(sizeof(struct poly));
                    b->cof=p->cof * q->cof;
                    b->exp=p->exp + q->exp;
                    a->next=b;
                    a=b;
                }
            }
            q=q->next;
        }
        p=p->next;
    }
    a->next=0;
    return temp;
}
int checklinklist(struct poly t,struct poly *p)
{
    int f=0;
    while(p!=0)
    {
        if(t.exp == p->exp)
        {
            p->cof=p->cof + t.cof; 
            f=1;
            break;
        }
        p=p->next;
    }
    return f;
}
void traverse(struct poly *p)
{
    while(p->next!=0)
    {
        printf("%dX^%d + ",p->cof,p->exp);
        p=p->next;
    }
    printf("%dX^%d ",p->cof,p->exp);
}
struct poly *createlinklist()
{
    struct poly *p, *q, *temp;
    char x[5];
    p=(struct poly *)malloc(sizeof(struct poly));  
    printf("\nEnter coefficient:  "); 
    scanf("%d", &p->cof);
    printf("\nEnter exp: ");
    scanf("%d",&p->exp);
    temp=p;
    while(1)
    {
        printf("Do you continue yes/no");
        scanf("%s",x);
        if (strcmp(x,"no")==0)
                break;
        q=(struct poly *)malloc(sizeof(struct poly));
        p->next=q; //joint p&q
        p=q; // p is shifted to q position
        printf("Enter coefficient:  "); 
        scanf("%d", &p->cof);
        printf("Enter exp: ");
        scanf("%d",&p->exp);
    }
    p->next=0; //last node of linklist
    return temp; //return base address of linklist
}

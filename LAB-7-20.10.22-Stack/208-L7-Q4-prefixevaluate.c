//WAP to evalution of prefix expression single digit.

#include"stdio.h"
#include"stdlib.h"
#include"string.h"
struct node
{
    int data;
    struct node *link;
};
int main()
{
    struct node *p=0,*q;
    char x[100];
    int i;
    printf("\nEnter prefix expression: ");
    scanf("%s",x);
    for(i=strlen(x)-1;i>0;i--)
    {
        if(x[i]>=48 && x[i]<=57)
        {
            if(p==0)
            {
                p=malloc(sizeof(struct node));
                p->link=0;
                p->data=x[i];
            }
            else
            {
                q=malloc(sizeof(struct node));
                q->link=p;
                p=q;
                p->data=x[i];
            }
        }
        else
        {
            int c;
            int b=p->data-48;
            p=p->link;
            int a=p->data-48;
            if(x[i]=='*')
                c=a*b;
            if(x[i]=='+')
                c=a+b;
            if(x[i]=='-')
                c=a-b;
            if(x[i]=='/')
                c=a/b;
            if(x[i]=='%')
                c=a%b;
            
            p->data=c+48;
        }
    }
    printf("\nEvalution is: %d",p->data-48);
}
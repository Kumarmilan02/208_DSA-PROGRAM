//WAP TO REVERSE A STACK USING RECURSION.
/*==METHOD-"01"== **/

#include"stdio.h"
int x[5];
int i=-1;
void push(int num)
{
    i++;
    x[i]=num;
}
int pop()
{
    int k=x[i];
    i--;
    return k;
}
void print()
{
    int j;
    if(i==-1)
    {
        printf("\nStack 1 is empty");
    }
    else
    {
        for(j=i;j>-1;--j)
        {
            printf("%d |",x[j]);
        }
    }
}
int reverse()
{
    int *temp;
    int j=0,k=i;
    while(k>=0)
    {
        temp[j]=pop();
        j++;
    } 
    x[5]=temp[5];
    print();
    return temp;  
}
int main()
{
    int n,num,*s;
    do
    {
        printf("\n==stack==");
        printf("\n1.push");
        printf("\n2.pop");
        printf("\n3.print");
        printf("\n4.Reverse");
        printf("\n0.Stop");
        printf("\nEnter choice: ");
        scanf("%d",&n);
        if(n==1)
        {
            if(i>5)
            {
                printf("\nStack overflow");
                continue;
            }
            printf("\nEnter Data: ");
            scanf("%d",&num);
            push(num);
        }
        else if(n==2)
        {
            if(i==-1)
            {
                printf("Stack underflow");
                continue;
            }
            int k=pop();
            printf("poped: %d",k);
        }
        else if(n==3)
        {
            print();
        }
        else if(n==4)
        {
            s=reverse();
            print();
        }
    } while (n!=0);
    return 0;
}

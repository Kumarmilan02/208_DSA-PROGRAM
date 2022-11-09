/*wAP TO IMPLEMENT TWO STACK IN ONE ARRAY.*/

#include"stdio.h"
#include"conio.h"
#define size 10
int stack[size];
int top1=-1,top2=size;
void push1(int data)
{
    if(top1==top2-1 || top1==stack[size] || top2==-1)
        printf("\nStack is overflow");
    else
        top1++;
        stack[top1]=data;
}
void push2(int data)
{
    if(top1==top2-1 || top1==stack[size] || top2==-1)
        printf("\nStack is overflow");
    else
        top2--;
        stack[top2]=data;
}
int pop1()
{
    int data;
    if(top1==-1)
    {
        printf("\nStack 1 Underflow");
    }
    else
    {
        data=stack[top1];
        top1--;
        printf("\nPopped from stack 1: %d",data);
    }
}
int pop2()
{
    int data;
    if(top2==size)
    {
        printf("\nStack 2 Underflow");
    }
    else
    {
        data=stack[top2];
        top2++;
        printf("\nPopped from stack 2: %d",data);
    }
}
void print1()
{
    int i;
    if(top1==-1)
    {
        printf("\nStack 1 is empty");
    }
    else
    {
        for(i=top1;i>-1;--i)
        {
            printf("%d |",stack[i]);
        }
    }
}
void print2()
{
    int i;
    if(top2==size)
    {
        printf("\nStack 2 is empty");
    }
    else
    {
        for(i=top2;i<size;i++)
        {
            printf("%d |",stack[i]);
        }
    }
}
int main()
{
    int n,ch;
    do
    {
        printf("\n1.push into stack 1");
        printf("\n2.push into stack 2");
        printf("\n3.pop from stack 1");
        printf("\n4.pop from stack 2");
        printf("\n5.Print stack 1");
        printf("\n6.Print stack 2");
        printf("\n0.stop");
        printf("\nEnter choice: ");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("\nEnter data in stack 1:  ");
            scanf("%d",&n);
            push1(n);
        } 
        else if(ch==2)
        {
            printf("\nEnter data in stack 2:  ");
            scanf("%d",&n);
            push2(n);
        }     
        else if(ch==3)
        {
            pop1();
        }
        else if(ch==4)
        {
            pop2();
        }
        else if(ch==5)
        {
            print1();
        }
        else if(ch==6)
        {
            print2();
        }
        else 
            printf("\ninvalid choice.");
    }while(ch!=0);
    return 0;
}


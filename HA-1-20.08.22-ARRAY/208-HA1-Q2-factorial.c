//WAP in C to find factorial of a number using function.

#include"stdio.h"
int factorial(int);
int main()
{
        int n,x;
        printf("\nEnter a number :");
        scanf("%d",&n);
        x=factorial(n);
        printf("\n %d!= %d",n,x);
}
int factorial(int n)
{
        int f=1;
        while(n>0)
        {
                f=f*n;
                n--;
        }
        return f;
}

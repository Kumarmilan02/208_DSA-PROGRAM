//WAP to input a number and test it is a prime or not.

#include "stdio.h"
#include "math.h"
int prime(int);
int main()
{
        int n;
        printf("\nEnter any number: ");
        scanf("%d",&n);
        int k=prime(n);
        if(n==1)
                printf("\n1 is neither prime nor composite.");
        else
        {
                if(k==1)
                        printf("\n %d is  prime number.",n);
                else
                        printf("\n %d is not a prime number.",n);
        }


}
int prime(int a)
{
        int i,q;
        int p=a/2;
        for(i=2;i<=p;i++)
        {
                q=a%i;
                if( q==0)
                 break;
        }
        return q;
}


//WAP to input a number and check it is an Armstrong number or not.

#include "stdio.h"
#include "math.h"
int main()
{
        int n,c=0,r,sum=0,m;
        printf("\nEnter the digits: ");
        scanf("%d",&n);
        m=n;

        while(n!=0)
        {
                c++;
                n=n/10;
        }
        
        n=m;
        while(n!=0)
        {
                r=n%10;
                sum=sum+pow(r,c);
                n=n/10;
        }
        if(sum==m)
                printf("\n%d is a Amstrong number.",m);
        else
                printf("\n%d is not amstrong number.",m);
        return 0;
}

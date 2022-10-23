//manu driven program

#include<stdio.h>
#include"math.h"
int main()
{
    int choice,num;
    while(choice!=5)
    {
        printf("\n1.Odd or even\n2.Prime or not\n3.palindrome/Not Palindrome \n4.Armstrong/Not Armstrong number\n5.Exit\n");
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter an integer: ");
                scanf("%d", &num);
                int n=num;
                if(num%2==0)
                    printf("\n%d is Even Number.\n\n",n);
                else
                    printf("\n%d is Odd Number.\n\n",n);
                break;
            case 2:
                int i,q,flag;
                printf("\nEnter any number: ");
                scanf("%d",&num);
                int p=num/2;
                for(i=2;i<=p;i++)
                {
                    q=num%i;
                    if( q==0)
                    {
                        flag=1;
                        break;
                    }
                }
                if(n==1)
                    printf("\n1 is neither prime nor composite.");
                else
                {
                    if(flag==0)
                        printf("\n%d is prime number.",num);
                    else
                        printf("\n%d is not a prime number.",num);
                }
                break;
            case 3:
                int temp,rev=0,remainder;
                printf("\nEnter a number:  ");
                scanf("%d",&num);
                temp = num;
                while( num!=0 )
                {
                    remainder = num % 10;
                    rev = rev*10 + remainder;
                    num /= 10;
                }
                num=temp;
                if (rev==temp) 
                    printf("\n%d is a Palendrome. ",num);
                else
                    printf("\n%d is not palendrome. ",num);
                break;

            case 4:
                int c=0,r,sum=0,m;
                printf("\nEnter the digits: ");
                scanf("%d",&num);
                m=num;
                while(num!=0)
                {
                    c++;
                    num/=10;
                }
                num=m;
                while(num!=0)
                {
                    r=num%10;
                    sum=sum+pow(r,c);
                    num/=10;
                }
                if(sum==m)
                    printf("\n%d is a Amstrong number.",m);
                else
                    printf("\n%d is not amstrong number.",m);
                break;
            case 5:
                printf("\nExit");
                break;
            default:
                printf("Invalid");
                break;
        }
    }
    return 0;
}
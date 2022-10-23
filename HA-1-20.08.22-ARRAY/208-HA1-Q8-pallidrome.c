// WAP to input a number and test it is palindrome or not.

#include "stdio.h"
#include"string.h"
int pallidrome(int);
int main()
{
        int n;
        printf("\nEnter a number:  ");
        scanf("%d",&n);
        int k=pallidrome(n);
        if(k==0)
                printf("\n%d is a Palendrome. ",n);
        else
                printf("\n%d is not palendrome. ",n);
        return 0;
}
int pallidrome(int n )
{
    int temp, remainder, rev=0;
    temp = n;
    while( n!=0 )
    {
         remainder = n % 10;
        rev = rev*10 + remainder;
        n /= 10;
    }
    if ( rev == temp ) return 0;
    else return 1;
}

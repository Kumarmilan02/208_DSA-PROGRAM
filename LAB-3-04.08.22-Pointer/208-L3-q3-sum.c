//WAP to create an array of N elements, where the value of N is given by the user, and 
//then print the sum of all the elements of the array.

#include"stdio.h"
#include "stdlib.h"
 int main()
 {
    int n,*p,sum=0,i;
    printf("Enter the no of element in the array: ");
    scanf("%d",&n);
   
    p=(int *)malloc(n*sizeof(int));
    if(p==NULL)
    {
        printf("no space");
    }
    else
    {
        printf("Enter the elements of the array: ");
        {
            for(i=0;i<n;i++)
            {
                scanf("%d",&p[i]);
            }
        }
        printf("array is: ");
        {
            for(i=0;i<n;i++)
            {
                printf("%d\t",p[i]);
            }
        }
        for(i=0;i<n;i++)
        {
            sum= sum+p[i];
        }
        printf("The sum of the element is %d\n",sum);
        return 0;
    }
 }
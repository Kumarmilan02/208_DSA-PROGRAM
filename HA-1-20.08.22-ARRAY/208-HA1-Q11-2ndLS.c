//WAP to find out the second smallest and second largest element stored in an array.

#include <stdio.h>

int main()
{
    int n,i,j,temp;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    printf("Enter the array elements :");
    int a[n];                    //Array Declaration
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)         //Sorting Array
    {
        for(j=i+1; j<n ;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("\n The Array Elements are: \n") ;
    for (  i = 0 ; i < n ; i++)
        printf(" %d \t",a[i]) ;
    printf("\nThe second smallest element is %d",a[1]);   //Accessing the smallest element
    printf("\nThe second largest element is %d",a[n-2]);      //Accessing the largest element
    return 0;
}
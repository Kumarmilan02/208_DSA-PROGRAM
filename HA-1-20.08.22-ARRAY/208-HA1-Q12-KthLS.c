//WAP to find out the kth smallest and kth largest element stored in a dynamic array of n integers, where k<n.

#include "stdio.h"
#include "stdlib.h"
int main()
{
    int i,n,j,k,pos,temp,*arr;
    printf("Enter number of element in array:");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    printf("Enter elements is array:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("array:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    printf("\nSorted array\n");
    for(i=0;i<n;i++)
    {
        printf("%d  ",arr[i]);
    }
    printf("\nEnter the kth element to be searched: ");
    scanf("%d",&k);
    printf("\nSmallest %dth element is:  %d\n",k,arr[k-1]);
    printf("\nlargest %dth element is:  %d\n",k,arr[n-k]);
    return 0;

}            
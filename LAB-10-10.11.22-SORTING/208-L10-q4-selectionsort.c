/*SELECTION SORT [O(n^2)]*/


#include"stdio.h"
int main()
{
    int i,j,n,min_ind;
    printf("\nEnter size: ");
    scanf("%d",&n);
    int x[n];
    for(i=0;i<n;i++)
    {
        printf("Enter (%d) element: ",i);
        scanf("%d",&x[i]);
    }
    printf("\nDISPLAY BEFORE SELECTION SORTING: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",x[i]);
    }
    //selection sort mechanism
    for(i=0;i<n;i++)
    {
        min_ind=i;
        for(j=i+1;j<n;j++)
        {
            if(x[min_ind]>x[j])
                min_ind=j;
        }
        int temp=x[i];
        x[i]=x[min_ind];
        x[min_ind]=temp;
    }
    printf("\n\nDISPLAY AFTER SELECTION SORTING: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",x[i]);
    }
    printf("\n");
    return 0;
}


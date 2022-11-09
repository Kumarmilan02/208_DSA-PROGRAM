/*INSERTION SORT [O(n^2)]*/
//fastest sorting if most of the element is sorted


#include"stdio.h"
int main()
{
    int i,j,n,k;
    printf("\nEnter size: ");
    scanf("%d",&n);
    int x[n];
    for(i=0;i<n;i++)
    {
        printf("Enter (%d) element: ",i);
        scanf("%d",&x[i]);
    }
    printf("\nDISPLAY BEFORE INSERTION SORTING: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",x[i]);
    }
    //insertion sort mechanism
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(x[i]<x[j])
            {
                int temp=x[i];
                for(k=i;k>j;k--)
                    x[k]=x[k-1];
                x[j]=temp;
            }
        }
    }
    printf("\n\nDISPLAY AFTER INSERTION SORTING: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",x[i]);
    }
    printf("\n");
    return 0;
}

/*
loop style
_________________
i   | j
1   | 0  
2   | 0 1  
3   | 0 1 2
4   | 0 1 2 3 
5   | 0 1 2 3 4
___________________
*/
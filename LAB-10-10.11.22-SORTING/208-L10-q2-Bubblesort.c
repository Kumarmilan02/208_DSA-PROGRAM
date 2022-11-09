/*BUBBLE SORT [O(n^2)]*/


#include"stdio.h"
int main()
{
    int i,j,n;
    printf("\nEnter size: ");
    scanf("%d",&n);
    int x[n];
    for(i=0;i<n;i++)
    {
        printf("Enter (%d) element: ",i);
        scanf("%d",&x[i]);
    }
    printf("\nDISPLAY BEFORE BUBBLE SORTING: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",x[i]);
    }
    //bubble sort mechanism
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<(n-1)-i;j++)
        {
            if(x[j]>x[j+1])
            {
                int temp=x[j];
                x[j]=x[j+1];
                x[j+1]=temp;
            }
        }
    }
    printf("\n\nDISPLAY AFTER BUBBLE SORTING: ");
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
0   | 0 1 2 3 
1   | 0 1 2 
2   | 0 1
3   | 0
____________________
*/
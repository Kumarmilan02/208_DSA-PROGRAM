/*LINEAR SORT [O(n^2)]*/

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
    printf("\nDISPLAY BEFORE LINEAR SORTING: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",x[i]);
    }
    //linear sort mechanism
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(x[i]>x[j])
            {
                int temp=x[i];
                x[i]=x[j];
                x[j]=temp;
            }
        }
    }
    printf("\n\nDISPLAY AFTER LINEAR SORTING: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",x[i]);
    }
    return 0;
}

/*
loop style
_________________
i   | j
0   | 1 2 3 4
1   |   2 3 4
2   |     3 4
3   |       4
____________________
*/
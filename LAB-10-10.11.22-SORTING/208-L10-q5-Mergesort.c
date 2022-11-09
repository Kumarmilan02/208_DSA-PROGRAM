/*MERGE SORT [O(nlogn)*/
//divide logn times [(low+up)/2]
//merge logn times (conquer)


#include"stdio.h"
void merge(int x[],int low,int m,int up,int n);
void divide(int x[],int low,int up,int n)
{
    int m;
    if(low < up)
    {
        m=(low+up)/2;
        divide(x,low,m,n);
        divide(x,m+1,up,n);
        merge(x,low,m,up,n);
    }
}
void merge(int x[],int low,int m,int up,int n)
{
    int i=low,j=m+1,k=low;
    int z[n];
    while(i<=m && j<=up)
    {
        if(x[i]<x[j])
        {
            z[k]=x[i];
            k++;
            i++;
        }
        else
        {
            z[k]=x[j];
            k++;
            j++;
        }
    }
    //rest part of i
    while(i<=m)
    {
        z[k]=x[i];
        k++;
        i++;
    }
    //rest part of j
    while(j<=up)
    {
        z[k]=x[j];
        k++;
        j++;
    }
    for(i=low;i<=up;i++)
    {
        x[i]=z[i];
    }
}
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
    printf("\nDISPLAY BEFORE MERGE SORTING: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",x[i]);
    }
    divide(x,0,n-1,n);
    printf("\nDISPLAY AFTER MERGE SORTING: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",x[i]);
    }
}
    
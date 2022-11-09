//QUICK SORT [O(nlogn)]


#include"stdio.h"
void quick_sort(int [],int,int);
int position(int [],int ,int);
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
    printf("\nDISPLAY BEFORE QUICK SORT: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",x[i]);
    }
    quick_sort(x,0,n-1);
    printf("\nDISPLAY AFTER QUICK SORT: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",x[i]);
    }
}
void quick_sort(int x[],int low,int up)
{
    int p;//pivot
    if(low<up)
    {
        p=position(x,low,up);
        quick_sort(x,low,p-1);
        quick_sort(x,p+1,up);
    }
}
int position(int x[],int low,int up)
{
    int left=low,right=up,p,temp;
    while(left<right)
    {
        p=(left+right)/2;
        while(x[p]>x[left])
                left++;
        if(x[p]<x[left])
        {
            temp=x[left];
            x[left]=x[p];
            x[p]=temp;
            p=left; 
        }
        while (x[p]<x[right])
        {
            right--;
        }
        if(x[p]>x[right])
        {
            temp=x[left];
            x[left]=x[p];
            x[p]=temp;
            p=right;
        }
    }
    return p;
}

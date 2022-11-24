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
        printf("%d\t",x[i]);
    }
    quick_sort(x,0,n-1);
    printf("\n\nDISPLAY AFTER QUICK SORT: ");
    for(i=0;i<n;i++)
    {
        printf("%d\t",x[i]);
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
int position(int x[],int left,int right)
{
    int i=left,j=right,p,temp;
    p=(i+j)/2;
    if(i<j)
    {
        if(x[p]<x[i])
        {
            temp=x[i];
            x[i]=x[p];
            x[p]=temp;
            p=i; 
        }
        else
        while(x[p]> x[i] )
                i++;
        if(x[p]>x[j])
        {
            temp=x[j];
            x[j]=x[p];
            x[p]=temp;
            p=j;
        }
        else
        while (x[p]<x[j])
        {
            j--;
        }
        quick_sort(x,left,p);
        quick_sort(x,p+1,right);
    }
    return p;
}

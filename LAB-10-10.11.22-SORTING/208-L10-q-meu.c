//SORTIN IN MENU DRIVEN PROGRAM.(INTEGERS)

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
void insertion(int x[],int n)
{
    int i,j,k;
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
}
void selection(int x[],int n)
{
    int i,j,min_ind;
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
}
void bubble(int x[],int n)
{
    int i,j;
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
}
void quick_sort(int x[],int low,int up)
{
    int p;//pivot
    if(low<up)
    {
        p=pos(x,low,up);
        quick_sort(x,low,p-1);
        quick_sort(x,p+1,up);
    }
}
int pos(int x[],int left,int right)
{
    int i=left,j=right,p,temp;
    if(i<j)
    {
        p=(i+j)/2;
        while(x[p]>x[i])
                i++;
        if(x[p]<x[i])
        {
            temp=x[i];
            x[i]=x[p];
            x[p]=temp;
            p=i; 
        }
        while (x[p]<x[j])
        {
            j--;
        }
        if(x[p]>x[j])
        {
            temp=x[j];
            x[j]=x[p];
            x[p]=temp;
            p=j;
        }
        quick_sort(x,left,p);
        quick_sort(x,p+1,right);
    }
    return p;
}

void display(int x[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",x[i]);
    }
}
void heapify(int arr[], int size, int i)
{
    int max = i,temp;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] > arr[max])
        max = left;

    if (right < size && arr[right] > arr[max])
        max = right;

    if (max != i)
    {
        // sorting logic by using temporary variable
        temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;
        heapify(arr, size, max);
    }
}

void heapSort(int arr[], int size)
{
    int i,temp;
    for (i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);
    for (i = size - 1; i >= 0; i--)
    {
        // swaping logic
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}
int main()
{
    int i,j,n,ch;
    printf("\nEnter size: ");
    scanf("%d",&n);
    int x[n];
    for(i=0;i<n;i++)
    {
        printf("Enter (%d) element: ",i+1);
        scanf("%d",&x[i]);
    }
    printf("\nDISPLAY BEFORE SORTING: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",x[i]);
    }
    while(ch!=0)
    {
        printf("\n\nSORTING");
        printf("\n1.MERGE SORT");
        printf("\n2.INSERTION SORT");
        printf("\n3.SELECTION SORT");
        printf("\n4.BUBBLE SORT");
        printf("\n5.QUICK SORT");
        printf("\n6.HEAP SORT");
        printf("\nEnter choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\n==Merge sort==");
                divide(x,0,n-1,n);
                printf("\n\nDISPLAY AFTER MERGE SORTING:  ");
                display(x,n);
                break;
            case 2:
                printf("\n\n==Insertion Sort==");
                insertion(x,n);
                printf("\nDISPLAY AFTER INSERTION SORTING: ");
                display(x,n);
                break;
            case 3:
                printf("\n\n==Selection Sort==");
                selection(x,n);
                printf("\nDISPLAY AFTER SELECTION SORTING: ");
                display(x,n);
                break;
            case 4:
                printf("\n\n==Bubble Sort==");
                bubble(x,n);
                printf("\nDISPLAY AFTER BUBBLE SORTING:  ");
                display(x,n);
                break;
            case 5:
                printf("\n\n==QUICK Sort==");
                quick_sort(x,0,n-1);
                printf("\nDISPLAY AFTER QUICK SORTING:  ");
                display(x,n);
                break;
            case 6:
                printf("\n\n==Heap Sort==");
                heapSort(x,n);
                printf("\nDISPLAY AFTER HEAP SORTING:  ");
                display(x,n);
                break;
            default:
                printf("\nInvalid choice: ");
                break;
        }
    }
    return 0;
}
    
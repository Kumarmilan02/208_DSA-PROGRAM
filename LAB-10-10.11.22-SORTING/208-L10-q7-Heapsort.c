// heap sort (O(nlogn)
/*1.create heap
2.Heapify-interchange the value of parent and child node in heap sort.
3.swap(1st element with nth position.)
if[l>r and l>p then swap l and p] and [r>l && r>p then swap r and p]
i=0(root),[2i+1]=left of treee ,[2i+2]-right of tree.*/

#include <stdio.h>
int temp;
void heapify(int arr[], int size, int i)
{
    int max = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] > arr[max])//left child is larger than root
        max = left;

    if (right < size && arr[right] > arr[max])//right child is larger than root
        max = right;

    if (max != i)//if largest is not root
    {
        // sorting logic by using temporary variable
        temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;
        heapify(arr, size, max);//heapfit the affected tree
    }
}

void heapSort(int arr[], int size)
{
    int i;
    for (i = (size / 2)-1 ; i >= 0; i--)//i=size/2-1;i>=0;i--[leaf node]BUILD MAX HEAP
        heapify(arr, size, i);
    for (i = size - 1; i >= 0; i--)//swapping root node with  leaf node of parents
    {
        // move current root to end
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);//used to reduced heap
    }
}
int main() // defining main()
{
    int i,size;
    printf("\nEnter size: ");
    scanf("%d",&size);
    int arr[size];
    for(i=0;i<size;i++)
    {
        printf("Enter (%d) element: ",i);
        scanf("%d",&arr[i]);
    }
    printf("\nDISPLAY BEFORE HEAP SORTING: ");
    for(i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    heapSort(arr, size);
    printf("\nDISPLAY BEFORE HEAP SORTING:"); // printing the sorted array
    for (i = 0; i < size; ++i)
        printf("%d ", arr[i]);
    return 0;
}
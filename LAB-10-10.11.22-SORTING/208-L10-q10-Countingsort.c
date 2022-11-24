// counting sort O(n)

#include <stdio.h>
#define MAX 255

void countSort(int array[], int size)
{
    int output[MAX];
    int count[MAX];
    int max = array[0];

    // Here we find the largest item in the array
    for (int i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    // Initialize the count for each element in array to 0
    for (int i = 0; i<= max; ++i)
    {
        count[i] = 0;
    }

    // For each element we store the count
    for (int i = 0; i < size; i++)
    {
        count[array[i]]++;
    }

    // Store the cummulative count of each array
    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }

    // Search the index of each element of the actual array in count array, and
    // place the elements in output array
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    // Transfer the sorted items into actual array
    for (int i = 0; i < size; i++)
    {
        array[i] = output[i];
    }
}
int main()
{
    int n,i;
    printf("\nEnter size: ");
    scanf("%d",&n);
    int x[n];

    for(i=0;i<n;i++)
    {
        printf("Array (%d) element :  ",i);
        scanf("%d",&x[i]);
    }

    printf("\nBEFORE COUNTING SORT:  ");
    for (i=0; i<n; i++)
        printf("%d ", x[i]);
    printf("\n");
    countSort(x,n);
    printf("\nAFTER COUNTING SORT: ");
    for (i=0; i<n; i++)
        printf("%d ", x[i]);
    return 0;
}


//1.Find max element in an array x.
//2.Then create an array of max element whose all elements are zero initially
//3.Then increment the new array value 1 by seeing array(x) 
//4.Then sort array
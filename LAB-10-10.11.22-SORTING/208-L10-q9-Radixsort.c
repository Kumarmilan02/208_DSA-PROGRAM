// RAdix sort o(kn)

#include <stdio.h> //including library files

int max(int a[]);         // declaring functions
void radix_sort(int a[]); // declaring functions
void main()               // defining main()
{
    int i;
    int a[10] = {92, 106, 365, 90, 33, 19, 72, 56, 45, 12}; // initializing array with values
    radix_sort(a);
    printf("\n The sorted list is: \n"); // printing the sorted list
    for (i = 0; i < 10; i++)
        printf(" %d", a[i]);
}

int max(int a[]) // giving the definition to max()
{
    int max = a[0], i; // finiding the largest number
    for (i = 1; i < 10; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}
void radix_sort(int a[]) // providing definition to radix_sort
{
    int bucket[10][10], bucket_count[10];                     // declaring variables
    int i, j, k, remainder, count = 0, divisor = 1, maxi, pass; // declaring variables
    maxi = max(a);
    while (maxi > 0)
    {
        count++;
        maxi /= 10;
    }
    for (pass = 0; pass < count; pass++) // Initialization of the buckets
    {
        for (i = 0; i < 10; i++)
            bucket_count[i] = 0;
        for (i = 0; i < 10; i++)
        {
            // sort the numbers according to the digit at passth place
            remainder = (a[i] / divisor) % 10;
            bucket[remainder][bucket_count[remainder]] = a[i];
            bucket_count[remainder] += 1;
        }
        // collect the numbers after PASS pass
        i = 0;
        for (k = 0; k < 10; k++)
        {
            for (j = 0; j < bucket_count[k]; j++)
            {
                a[i] = bucket[k][j];
                i++;
            }
        }
        divisor *= 10;
    }
}
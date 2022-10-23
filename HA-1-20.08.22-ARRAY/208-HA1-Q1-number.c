//WAP in C to using function input 10 numbers in an array and display it.

#include"stdio.h"
void printarray(int *a);
int main()
{
    int a[10];
    int i;
    for(i=0;i<10;i++)
    {
        printf("Enter %d Element: ",i+1);
        scanf("%d",&a[i]);
    }
    printarray(a);
}
void printarray(int *a)
{
    int i;
    printf("\nDISPLAY 10 ELEMENTS ARE: ");
    for(i=0;i<10;i++)
    {
        printf("%d ",a[i]);
    }
}
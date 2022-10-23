//WAP program to input n number of elements in an dynamic array . Write a menu to do the following operations in the array.
//a)Insert an element. b)Delete and element. c)Reverse the elements. d)Search an element.
//e)Sort all elements. f)Display all the elements. g)Display all composite elements.h)Quit.

#include<stdio.h>
#include<stdlib.h>
void insertEle(int *arr, int n){
    int x, pos;
    printf("Enter the number to be inserted: ");
    scanf("%d", &x);
    printf("Enter the position: ");
    scanf("%d", &pos);
    n++;
    for(int i=n-1;i>=pos;i--)
        arr[i]=arr[i-1];
    arr[pos-1]=x;
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void deleteEle(int *arr, int n){
    int pos;
    printf("Enter the position of the element to be deleted: ");  
    scanf(" %d", &pos);  
    if (pos>=n+1)  
        printf ("\nDeletion is not possible in the array.");  
    else  
    {  
        for (int i = pos; i<n -1; i++)   
            arr[i] = arr[i+1];    
        printf ("\nThe resultant array is: \n");    
        for (int i = 0; i<n - 1; i++)   
            printf ("%d ", arr[i]);   
    }
}

void reverse(int *arr, int n){
    int temp;
    for(int i = 0; i<n/2; i++){
        temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
    printf("The reversed array is: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}

void search(int *arr, int n){
    int i,x;
    printf("Enter the item to be searched: ");
    scanf("%d", &x);
    for(i=0;i<n;i++)
    {
        if(arr[i]==x)
        {
            printf("The element is found in the position = %d", i + 1);
            return;
        }
    }
    printf("Element not found!");
}

void sort(int *arr, int n){
    int i,j,a;
    for (i = 0; i < n; ++i){
        for (j = i + 1; j < n; ++j)
        {
            if (arr[i] > arr[j]) 
            {
                a =  arr[i];
                arr[i] = arr[j];
                arr[j] = a;
            }
        }
    }
    printf("Sorted array: ");
    for (i = 0; i < n; ++i)
    printf("%d ", arr[i]);
}

void display(int *arr, int n){
    printf("The elements of the array are: ");
    for(int i=0; i<n; i++)
    printf("%d ", arr[i]);
}

void composite(int *arr, int n){
    int count,flag,i,j;
    printf("The composite numbers are: ");
    for(i=0;i<n;i++)
    {
        flag=0;
        for(j=2;j<arr[i];j++)
        {
            if(arr[i]%j==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            printf("%d ",arr[i]);
        }
    }
}

int main()
{
    int n,k, *arr;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    printf("Enter the array elements: ");                   
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    while(n!=8)
    {  
        printf("\n");
        printf("1. Insert\n");
        printf("2. Deletion\n");
        printf("3. Reverse\n");
        printf("4. Search\n");
        printf("5. Sort\n");
        printf("6. Display\n");
        printf("7. Composite\n");
        printf("8. Quit\n");
        printf("Enter operation choice: ");
            scanf("%d", &k);

        switch(k)
        {
            case 1:
                insertEle(arr,n);
                break;
            case 2:
                deleteEle(arr,n);
                break;
            case 3:
                reverse(arr,n);
                break;
            case 4:
                search(arr,n);
                break;
            case 5:
                sort(arr,n);
                break;
            case 6:
                display(arr,n);
                break;
            case 7:
                composite(arr,n);
                break;
            case 8:
                printf("Program has ended!");
                break;
            default:
            printf("Error! Enter valid choice.");
        }
    
    }
    return 0;
}
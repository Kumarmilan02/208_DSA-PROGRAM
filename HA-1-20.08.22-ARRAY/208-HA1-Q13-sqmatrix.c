// Let A be n X n square matrix array. WAP by using appropriate user defined functions for the following:
//a) Find the number of nonzero elements in A
//b) Find the sum of the elements above the leading diagonal.
//c) Display the elements below the minor diagonal.
//d) Find the product of the diagonal elements.

#include <stdio.h>

void non_zero(int row, int coloumn, int Arr[row][coloumn])
{
    int i, j, count = 0;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < coloumn; j++)
        {
            if (Arr[i][j] != 0)
            {
                count++;
            }
        }
    }
    printf("Number of non-zero elements are: %d\n", count);
}
void above_leading_diagonal_sum(int row, int coloumn, int Arr[row][coloumn])
{
    int i, j, sum = 0;
    for (i = 0; i < row - 1; i++)
    {
        for (j = i + 1; j < coloumn; j++)
        {
            sum += Arr[i][j];
        }
    }
    printf("Sum of the elements which are above the leading diagonal is: %d\n", sum);
}

void minor_diagonal_elements(int row, int coloumn, int Arr[row][coloumn])
{
    printf("Elements present below minor diagonal are: \n");
    int i, j;
    for (i = 0; i < row; i++)
    {
        printf("\t");
        for (j = 0; j < row; j++)
        {
            if (j > row - (i + 1))
                printf("%d  ", Arr[i][j]);
        }
        printf("\n");
    }
}

void product_digonal_elements(int row, int coloumn, int Arr[row][coloumn])
{
    int i, j, product = 1;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < coloumn; j++)
        {
            if (i == j)
            {
                product = product * Arr[i][j];
            }
        }
    }
    printf("Product of the diagonal elements: %d", product);
}

int main()
{
    int i, j, row, coloumn;
    printf("Enter the number of rows and coloumns: ");
    scanf("%d%d", &row, &coloumn);
    int  Arr[row][coloumn];
    for (i = 0; i < row; ++i)
    {
        for (j = 0; j < coloumn; ++j)
        {
            printf("Enter the element[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &Arr[i][j]);
        }
    }
    printf("\nEntered matrix: \n");
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < coloumn; ++j)
        {
            printf("%d  ", Arr[i][j]);
        }            
        printf("\n");
    }
    printf("\nThe final results are:\n");
    non_zero(row, coloumn, Arr);
    above_leading_diagonal_sum(row, coloumn, Arr);
    minor_diagonal_elements(row, coloumn, Arr);
    product_digonal_elements(row, coloumn, Arr);
    return 0;
}
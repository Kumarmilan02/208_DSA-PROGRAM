//WAP TO CONVERT LOWER TRIANGULAR MATRIX TO UPPER TRIANGULAR MATRIX.

#include"stdio.h"
int  main()
{ 
    int i, j,k=1,r,c,nzero=0;
    printf("Enter the number of rows and coloumns: ");
    scanf("%d%d", &r, &c);
    int  a[r][c],b[10][10];
    for(i=0;i<r;++i)
    {
        for(j=0;j<c;++j)
        {
            printf("Enter the element a[%d][%d]: ",i,j);
            scanf("%d", &a[i][j]);
            b[i][j]=a[i][j];
        }
    }
    printf("\n Matrix is: \n");
    for (i=0;i<r;++i)
    {
        for(j=0;j<c;++j)
        {
            printf("%d | ",a[i][j]);

        }            
        printf("\n");
    }
    for (i=0;i<r;++i)
    {
        for(j=0;j<c;++j)
        {
            if(i<j)
            {
                a[i][j]=0;
            }
        }         
    }
    printf("\nThe lower Tringular MAtrix is: \n");
    for (i=0;i<r;++i)
    {
        for(j=0;j<c;++j)
        {
            printf("%d | ",a[i][j]);
        }            
        printf("\n");
    }
    for(i=0;i<r;++i)
    {
        for(j=0;j<c;++j)
        {
            if(i>j)
            {
                b[i][j]=0;
            }
        }         
    }
    printf("\nThe Upper Tringular MAtrix is: \n");
    for (i=0;i<r;++i)
    {
        for(j=0;j<c;++j)
        {
            printf("%d | ",b[i][j]);
        }            
        printf("\n");
    }

    printf("\nconvert\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d | ",a[j][i]);
        }
        printf("\n");
    }
}
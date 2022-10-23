//WAP TO REPRESENT SPARSE (COLUMN MAJOR) TRIPLET MATRIX USING ARRAY.

#include"stdio.h"
int  main()
{ 
    int i, j,k=1,row,coloumn,nzero=0,triplet[10][10];
    printf("Enter the number of rows and coloumns: ");
    scanf("%d%d", &row, &coloumn);
    int  sparse[row][coloumn];
    for(i=0;i<row;++i)
    {
        for(j=0;j<coloumn;++j)
        {
            printf("Enter the element[%d][%d]: ",i,j);
            scanf("%d", &sparse[i][j]);
        }
    }
    printf("\nsparse matrix is: \n");
    for (i=0;i<row;++i)
    {
        for(j=0;j<coloumn;++j)
        {
            printf("%d  ", sparse[i][j]);
        }            
        printf("\n");
    }
    //count nonzero element
    for(i=0; i<row;i++)
    {
        for(j=0;j<coloumn;j++)
        {
            if (sparse[i][j]!=0)
            {
                nzero++;
            }
        }
    }
    //convert into triplet matrix(COLUMN MAJOR)
    triplet[0][0]=row;
    triplet[1][0]=coloumn;
    triplet[2][0]=nzero;
    for(i=0;i<row;i++)
    {
        for(j=0;j<coloumn;j++)
        {
            if (sparse[i][j]!=0)
            {
                triplet[0][k]=i;
                triplet[1][k]=j;
                triplet[2][k]=sparse[j][i];
                k++;
            }
        }
    }
    //display triplet matrix
    printf("Triplet representation of the given matrix is: \n");
    for(i=0;i<nzero+1;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d\t",triplet[i][j]);
        }
        printf("\n");
    }
}
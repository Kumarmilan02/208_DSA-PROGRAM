//WAP TO REPRESENT SPARSE (ROW MAJOR)TRIPLET MATRIX USING ARRAY.

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
            printf("%d | ", sparse[i][j]);
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
    //convert into triplet matrix(row triplet)
    triplet[0][0]=row;
    triplet[0][1]=coloumn;
    triplet[0][2]=nzero;
    for(i=0;i<row;i++)
    {
        for(j=0;j<coloumn;j++)
        {
            if (sparse[i][j]!=0)
            {
                triplet[k][0]=i;
                triplet[k][1]=j;
                triplet[k][2]=sparse[i][j];
                k++;
            }
        }
    }
    //display triplet matrix
    printf("Triplet representation of the given matrix is: \n");
    printf("\nROW|\tCOLUMN|\tNONZERO|\n");
    for(i=0;i<nzero+1;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d |",triplet[i][j]);
        }
        printf("\n");
    }
}
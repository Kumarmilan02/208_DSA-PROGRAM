//WAP to sort rows of a matrix having m rows and n columns in ascending & columns in descending order.

#include <stdio.h>
 
int main()
{
    int a[10][10], b[10][10];
    int i, j, k, temp, m, n;
    printf("\nEnter the number of row and column for matrix: ");
    scanf("%d %d",&m,&n);
    printf("Enter elements of matrix:\n");
    for (i=0;i<m;++i)
    {
        for (j=0;j<n;++j)
        {
            printf("Enter element a%d%d: ",i,j);
            scanf("%d", &a[i][j]);
			b[i][j]=a[i][j];
        }
        printf("\n");
    }
	printf("\nTHE given matrix is: \n");
    for (i=0;i<m;++i)
    {
        for (j=0;j<n;++j)
        {
             printf("%d\t",a[i][j]);
        }
        printf("\n");
	}
    printf("After arranging rows in ascending order\n");
    for (i=0;i<m;++i)
    {
        for (j=0;j<n;++j)
        {
            for (k=(j+1);k<n;++k)
            {
                if(a[i][j]>a[i][k])
                {
                    temp=a[i][j];
                    a[i][j]=a[i][k];
                    a[i][k]=temp;
                }
            }
        }
    }
    for (i=0;i<m;++i)
    {
        for (j=0;j<n;++j)
        {
            printf(" %d",a[i][j]);
        }
        printf("\n");
    }
    printf("After arranging the columns in descending order \n");
    for(j=0;j<n;++j)
    {
        for(i=0;i<m;++i)
        {
            for(k=i+1;k<m;++k)
            {
                if (b[i][j]<b[k][j])
                {
                    temp=b[i][j];
                    b[i][j]=b[k][j];
                    b[k][j]=temp;
                }
            }
        }
    }
    for(i=0;i<m;++i)
    {
        for(j=0;j<n;++j)
        {
            printf(" %d",b[i][j]);
        }
        printf("\n");
    }
}
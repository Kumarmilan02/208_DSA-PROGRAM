//WAP to allocate memory to a 2D matrix, take user input and print its elements.

#include<stdio.h>
#include<stdlib.h>

int main() {

	int** p;
	int i, j;

	int n;
	int m;
    printf("\n ENTER NUMBER OF ROWS: ");
    scanf("%d",&n);
    printf("\n ENTER NUMBER OF COLUMNS: ");
    scanf("%d",&m);
    //p is a double pointer which stores the address of each row of matrix based on number of rows
	p = (int**)malloc(n * sizeof(int*));
    //Now each element of P will store the addres of first element of each row and array is created with number of elements same as number of columns
	for (i = 0; i < n; ++i) {
	        p[i] = (int*)malloc(m * sizeof(int));
	}

	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			printf("\n ENTER: ");
            scanf("%d",&p[i][j]);
		}
        printf("\n NEXT ROW");
	}

	printf("Elements of 2D array: \n");
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}

	printf("\n");
}
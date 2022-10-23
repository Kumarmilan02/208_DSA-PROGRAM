//Write a function using pointers to add two matrices and to return the resultant matrix to the calling function. 

#include <stdio.h>
#include <stdlib.h>

void enter(int *x, int n){
    int i,j;
    printf("\n--ENTER DATA FOR MATRIX--");
    for (i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("\nENTER NO.- ");
            scanf("%d",(x+(i*n)+j));
        }
        printf("\n NEXT ROW: ");
    }
}
void show(int *x, int n){
    int i,j;
    printf("\n --DISPLAY--\n ");
    for (i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("|%d\t",*(x+(i*n)+j));
            
        }
        printf("\n");
    }
}

int* addmat(int *x, int* y,int n){
    int i,j;
    printf("\n Summing Operation-- ");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            *(y+ (i*n) + j)=*(y+ (i*n) + j) + *(x + (i*n)+j);

        }
    }
    return y;



}

int main(){
    int n;
    printf("\n ENTER SIZE OF MATRIX: ");
    scanf("%d",&n);
    int A[n][n];
    int B[n][n];
    //entry of data in both
    printf("\n ENTRY FOR A: ");
    enter(&A[0][0],n);
    printf("\n ENTRY FOR B: ");
    enter(&B[0][0],n);
    show(&A[0][0],n);
    show(&B[0][0],n);
    //addition and returning
    int* ptr=addmat(&A[0][0],&B[0][0],n);
    show(ptr,n);
    return 0;
}
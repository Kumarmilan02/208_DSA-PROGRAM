//WAP that reads a series of numbers from the user and stores each integer in a 
//dynamically allocated array and prints the sum. Show the usage of realloc() as well as free() also.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(){
    int a,n,b,c;
    int* arr;
    int* ptr;
    printf("\n ENTER SIZE OF ARRAY: \n");
    scanf("%d",&n);
    arr=(int*)malloc(n*(sizeof(int)));
    if(arr==NULL){
        printf("\n NO SPACE.");
        exit(0);
    }
    int cnt=1;
    int i=0;
    while(cnt!=0){
        int inc=0;
        for(i;i<n;i++){
            printf("\n ENTER: ");
            scanf("%d",&arr[i]);
        }
        printf("\n CONTINUE: ?");
        scanf("%d",&cnt);
        if(cnt==1){
            printf("\n BY HOW MUCH TO INCREASE ? ");
            scanf("%d",&inc);
            n=n+inc;
            ptr=(int*)realloc(arr,n*(sizeof(int)));
            if(ptr==NULL){
                printf("\n NO SPACE.");
            }
            else{
                arr=ptr;
            }
        }
    }
    int sum=0;
    printf("\n--DISPLAY--\n");
    for(i=0;i<n;i++){
        printf("\t%d",*(arr+i));
        sum+=*(arr+i);
    }
    printf("\n SUM: %d",sum);
    free(arr);
    free(ptr);
    return 0;
}
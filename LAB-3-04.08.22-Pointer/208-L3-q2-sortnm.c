//Write a program to read in an array of names and to sort them in alphabetical order. 
//use sort function that receives pointers to the functions strcmp, and swap.
//sort in turn should call these functions via the pointers. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct name{
    char nam[100];
};

void enter(struct name* d,int n){
    int i,j,k;
    for(i=0;i<n;i++){
        printf("\n ENTER NAME %d : ",i+1);
        scanf("%s",d[i].nam);
    }
}
void show(struct name* d,int n){
    int i,j,k;
    printf("\n --DISPLAY--");
    for(i=0;i<n;i++){
        printf("\nNAME %d : %s ",i+1,d[i].nam);
    }
}
void sort(struct name* d,int n){
    int i,j;
    printf("\n SORTING IN ALPHABETICAL ORDER: ");
    struct name temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            //if(d[j].nam[0]>d[j+1].nam[0]){ 
            if(strcmp(d[j].nam,d[j+1].nam)>0){
                    temp = d[j]; 
                    d[j] = d[j+1]; 
                    d[j+1] = temp;
            }

        }
    }

}
int main(){
    int n;
    printf("\n Enter Size: ");
    scanf("%d",&n);
    struct name na[n];
    enter(na,n);
    show(na,n);
    sort(na,n);
    show(na,n);
    return 0;

}
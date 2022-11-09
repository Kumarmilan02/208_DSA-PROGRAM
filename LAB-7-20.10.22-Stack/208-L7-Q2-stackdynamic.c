//WAP TO IMPLEMENT PUSH AND POP OPERATION USING DYNAMIC ARRAY.

#include <stdio.h>
#include <stdlib.h>

void push(int* arr,int* N,int* t){
    if(*t==(*N)-1){
        printf("\n OVERFLOW.");
        return;
    }
    *t=*t+1;
    printf("\n ENTER ELEMENT: ");
    scanf("%d",&arr[*t]);
    return;
}
void pop(int* arr,int* N,int* t){
    if(*t==-1){
        printf("\n UNDERFLOW.");
        return;
    }
    int itm=arr[*t];
    printf("\n ITEM POPED: %d",itm);
    *t=*t-1;
    return;
}
void display(int* arr,int *t){
    if(*t==-1){
        printf("\n NO ELEMENTS.");
        return;
    }
    printf("\n STACK: ");
    for(int i=0;i<=*t;i++){
        printf(" %d| ",arr[i]);
    }
    return;
}
int main(){
    int *stack;
    int top=-1;
    int n;
    printf("\n ENTER LIMIT OF STACK: ");
    scanf("%d",&n);
    stack=(int*)malloc(n*(sizeof(int)));
    int ch=1;
    while(ch!=4){
        printf("\n==STACK==\n");
        printf("\n1.PUSH.");
        printf("\n2.POP.");
        printf("\n3.DISPLAY.");
        printf("\n4.EXIT");
        printf("\n\nENTER CHOICE: ");
        scanf("%d",&ch);
        if(ch==1)
        {
            {
                printf("\n PUSHING\n");
                push(stack,&n,&top);
            }
            continue;}
        else if(ch==2){
                pop(stack,&n,&top);
                continue;}
        else if(ch==3){
                display(stack,&top);
                continue;}
    
        }
    return 0;
}
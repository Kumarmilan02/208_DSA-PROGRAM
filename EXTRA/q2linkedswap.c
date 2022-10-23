//WAP TO REVERSE THE NODES OF SINGLE LINKED LIST
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link;
}*head=NULL,*revhead=NULL;

void display(){
    struct node*ptr;
    ptr=head;
    while(ptr->link!=NULL){
        printf("%d-->",ptr->data);
        ptr=ptr->link;
    }
    printf("%d-->",ptr->data);


}

void create(){
    struct node *newnode,*current;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\n ENTER DATA: ");
    scanf("%d",&(newnode->data));
    newnode->link=NULL;
    if(head==NULL){
        head=newnode;
    }
    else{
        current=head;
        while(current->link!=NULL){
            current=current->link;
        }
        current->link=newnode;
    }
}
void swap(int k){
    int i;
    struct node* current,*temp;
    current=head;
    for(i=1;i<k;i++){
        temp=current;
        current=current->link;
    }
    temp->link=current->link;
    current->link=temp->link->link;
    temp->link->link=current;

}
int main(){
    char ch='Y';
    do{
        create();
        printf("\n DO YOU NEED MORE NODES? PRESS Y: ");
        scanf(" %c",&ch);
    }
    while((ch=='Y')||(ch=='y'));
    display();
    printf("\n ENTER POSITION: ");
    int p;
    scanf("%d",&p);
    swap(p);
    display();
    return 0;

}

//WAP TO CHECK A SINGLE LINKLIST IS PALLIDROME OR NOT.

#include <stdio.h>
#include <stdlib.h>
struct node 
{
  int data;
  struct node *next;
}*head=NULL;
void insert(int num) 
{
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data  = num;
    newNode->next = head;
    head = newNode;
}
 struct node* reverseCopy(struct node *head) 
 {
    struct node *newHead = NULL, *temp;
    if (head == NULL) { 
       printf("Error : Invalid node pointer !!!\n");       
       return;  
    }
     
    while(head != NULL) {
        temp = (struct node*) malloc(sizeof(struct node));
        temp->data = head->data;
        temp->next = newHead;
        newHead = temp;
        head = head->next;
    }
     
    return newHead;
}
 
int compareLinkedList(struct node* LLOne, struct node* LLTwo){ 
    while (LLOne != NULL && LLTwo != NULL) {
        if (LLOne->data != LLTwo->data)
            return 0;
        LLOne = LLOne->next;
        LLTwo = LLTwo->next;
    }
    return (LLOne == NULL && LLTwo == NULL);
}
void printLinkedList(struct node *nodePtr) {
  while (nodePtr != NULL) {
     printf("%d", nodePtr->data);
     nodePtr = nodePtr->next;
     if(nodePtr != NULL)
         printf("-->");
  }
}
  
int main() {
    struct node *reverseLL;
    int i, nodeCount, temp;
    printf("Enter number of Nodes in Linked List\n");
    scanf("%d", &nodeCount);
    printf("Enter %d integers\n", nodeCount);
    for(i = 0; i < nodeCount; i++){
        scanf("%d", &temp);
        insert(temp);
    } 
     
    printf("\nLinked List\n");
    printLinkedList(head);
     
    /* Reverse Input Linked List */
    reverseLL = reverseCopy(head);
     
    if(compareLinkedList(head, reverseLL)){
        printf("\nPalindrome Linked List\n");
    } else {
        printf("\nNot a Palindrome Linked List\n");
    }
     
    return 0;
}
//Create enqueue and dequeue operation using linklist in circular queue.
#include<stdio.h>
#include<stdlib.h>
struct queue
{
	int data;
	struct queue* next;
};
struct queue *f = NULL;
struct queue *r = NULL;
void enqueue(int d)
{
	struct queue* q;
	q= (struct queue*)malloc(sizeof(struct queue));
	q->data = d;
	q->next = NULL;
	if((r==NULL)&&(f==NULL))
	{
		f = r = q;
		r->next = f;
	}
	else
	{
		r->next = q;
		r = q;
		q->next = f;
	}
} 
int dequeue() 
{
	struct queue* t;
	t = f;
	if((f==NULL)&&(r==NULL))
		printf("\nQueue is Empty.");
	else if(f == r){
		f = r = NULL;
		free(t);
	}
	else{
		f = f->next;
		r->next = f;
		free(t);
	}
}
void display()
{ 
	struct queue* t;
	t = f;
	if((f==NULL)&&(r==NULL))
		printf("\nQueue is Empty");
	else
	{
		printf("\nQUEUE IS: \n");
		while(t->next!=f)
		{
			printf("%d-->",t->data);
			t = t->next;
		}
		printf("%d--->",t->data);
	}
}
int main()
{
	int ch,n,i,data;
	do{
		printf("\n");
        printf("\n1.ENQUEUE");
        printf("\n2.DEQUEUE");
        printf("\n3.TRAVERSE");
        printf("\n0.STOP");
        printf("\nENTER UR CHOICE: ");
        	scanf("%d",&ch);
		switch(ch)
        {
			case 1:
				printf("\nEnter data to insert: ");
            	scanf("%d",&data);
				enqueue(data);
				break;
			case 3:
				display();
				break;
			case 2:
				 data=dequeue();
				 printf("DELETE: %d",data);
				break;
			case 0:
				break;
			default:
				printf("\nIncorrect Choice");
			
		}
	}while(ch!=0);
	return 0;
}
/*WAP TO EVALUATE PREFIX EXPRESSION FOR SINGLE DIGIT USING STACK.*/

#include<stdio.h>
#include<conio.h>
#include<string.h>

int s[50];
int top=0;

void push(int ch);
int pop();

int main()
{
	int a,b,c,i;
	char x[50];
	//Clrscr();

	printf("\nEnter the prefix :");
	gets(x);
	for(i=strlen(x)-1;i>=0;i--)
	{
		if(x[i]=='+')
		{
			c=pop()+pop();
			push(c);
		}
		else if(x[i]=='-')
		{
			a=pop();
			b=pop();
			c=a-b;
			push(c);
		}
		else if(x[i]=='*')
		{	a=pop();
		    b=pop();
		    c=b*a;
		    push(c);
		}
		else if(x[i]=='/')
		{
			a=pop();
			b=pop();
			c=a/b;
			push(c);
		}
        else
		{
			push(x[i]-48);
			//printf("\n INT=%d - CHAR=%d",prefix[i]-48,c);
		}
	}
	printf("\nEvalution = %d",pop());

	getch();
	return 0;
}

void push(int ch)
{
	top++;
	s[top]=ch;
}

int pop()
{
	int ch;
	ch=s[top];
	top=top-1;
	return(ch);
}

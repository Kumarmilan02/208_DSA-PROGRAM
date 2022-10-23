#include <stdio.h>  
#define SIZE 8 
int array[SIZE];    
int t1 = -1;  
int t2 = SIZE;   
void push1 (int data)  
{    
    if (t1<t2 - 1)  
    {  
        t1++;  
        array[t1] = data;  
    }  
    else  
    {  
        printf ("Stack is full");  
    }  
}    
void push2 (int data)  
{  
    if (t1<t2 - 1)  
    {  
        t2--;  
        array[t2] = data;   
    }  
    else  
    {  
        printf("Stack is full..\n");  
    }  
}  
void pop1 ()  
{  
    if (t1 >= 0)  
    {  
        int popped = array[t1];  
        t1--;  
        printf ("popped stack 1: %d\n", popped);
    }  
    else  
    {  
        printf ("Stack is Empty \n");  
    }  
}  
void pop2 ()  
{     
    if (t2 < SIZE)  
    {  
        int popped= array[t2];  
        t2--;  
        printf ("popped stack 2:%d\n", popped);  
    }  
    else  
    {  
        printf ("Stack is Empty!\n");  
    }  
}  
void display_stack1 ()  
{  
    int i;  
    for (i = t1; i >= 0; --i)  
    {  
        printf ("%d ", array[i]);  
    }  
    printf ("\n");  
}    
void display_stack2 ()  
{  
        int i;  
        for (i = t2; i < SIZE; ++i)  
        {  
            printf ("%d ", array[i]);  
        }  
        printf ("\n");  
}
int main()  
{  
    int ar[SIZE];  
    int i,j,s;  
    int val;       
    for(i = 1; i <= t2; ++i)  
    {   
        printf("enter value:");
        scanf("%d",val)
        push1(val);  
        printf ("Value Pushed in Stack 1 is %d\n", i);
        printf("")  
    }  
   for (j=8; j>t1 ; j--)  
    {  
        push2(j);  
        printf ("Value Pushed in Stack 2 is %d\n", j);  
    }  
    display_stack1 ();  
    display_stack2 ();  
    printf ("Pushing Value in Stack 1 is %d\n", 5);  
    push1 (5);  
    val= t1 + 1;  
    while (val)  
    {  
        pop1 ();  
        --val;  
    }  
   pop1 ();  
   return 0;  
}  
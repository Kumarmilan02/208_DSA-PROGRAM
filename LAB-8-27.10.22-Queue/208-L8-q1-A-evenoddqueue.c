/*WAP TO IMPLEMENT A QUEUE WITH (i)LET THERE ARE 2 FIXED SIZE ARRAYS USED FOR IMPLEMENTATION OF QUEUE.*/
/*ONE ARRAY IS USED FOR EVEN AND OTHER IS USED FOR ODD ELEMENT.*/
/*(ii)INSERTION: IF EVEN ELEMENT IS COMES, AN EVEN ELEMENT ARRAY IS NOT FULL THEN ADD ELEMENT IN REAR END OF EVEN QUEUE.*/
/*IF AN EVEN ELEMENT COME AND EVEN ARRAY IS FULL THEN ADD ELEMENT IN ODD ARRAY.*/
/*DELETE: DELETE FRONT ELEMENT OF ARRAY HAVING MAXIMUM NO OF ELEMENT IN ARRAY*/
/*METHOD:-"01"-*/
#include"stdio.h"
#define max 5
int arr1[max],arr2[max];
int r1=-1,f1=-1,r2=-1,f2=-1;
void insert()
{
    int num;
    printf("\nEnter data: ");
        scanf("%d",&num);
    if((r1>4) && (r2>4))
    {
        printf("\nBoth Arr1 and Arr2 is Empty.");
    }
    else if(num%2==0)
    {
        if(r1>4)  //(f1==r1) 
        {   
            printf("\nEVEN arr1 is overflow.");
            arr2[r2]=num;
            r2++;
        }
        else
        {
            arr1[r1]=num;
            r1++;
        }
    }
    else 
    {
        if(r2 > max-1)
        {
            printf("ODD arr2 is overflow");
        }
        else
        {
            arr2[r2]=num;
            r2++;
        }
    }
}
int delete()
{
    if((r1-f1) >= (r2-f2))
    {
        int k=arr1[f1];
        f1++;
        return k;
    }
    else
    {
        int m=arr2[f2];
        f2++;
        return m;
    }
}
void display()
{
    int i,j;
    if(f1==-1)
    {
        printf("\nEven arr1 is empty.");
    }
    else
    {
        printf("\nEven ARR1 is: ");
        for(i=f1;i<r1;i++)
        {
            printf("%d\t",arr1[i]);
        }
    }
    printf("\n");
    if(f2==-1)
    {
        printf("\nOdd arr2 is empty.");
    }
    else
    {
        printf("\nOdd ARR2 is: ");
        for(j=f2;j<r2;j++)
        {
            printf("%d\t",arr2[j]);
        }
    }
}
int main()
{
    int n,num;
    do
    {
        printf("\n1.insert");
        printf("\n2.delete");
        printf("\n3.display");
        printf("\n0.stop");
        printf("\nChoice: ");
        scanf("%d",&n);
        if(n==1)
        {
            if(r1==-1 && r2==-1)
            {
                printf("start");
                r1=f1=r2=f2=0;
                continue;
            }
            insert();
        }
        else if(n==2)
        {   
            if(f1==-1 && f2==-1)
            {
                printf("\nUNDERFLOW");
            }
            else
            {
                if(f1==r1)
                {
                    r1=f1=-1;
                    printf("\narr1 is empty.");
                    continue;
                }
                if(f2==r2)
                {
                    r2=f2=-1;
                    printf("\nArr2 is empty");
                    continue;
                }
            }
            printf("Execute ");
            num=delete();
            printf(" delete:%d",num);
        }
        else if (n==3)
        {
            display();
        }
        else{
            printf("invalid choice.");
            }
    }while (n!=0);
    return 0;
}
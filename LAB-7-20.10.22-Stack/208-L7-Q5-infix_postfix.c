//WAP TO CONVERT INFIX TO POSTFIX EXPRESSION.
#include "stdio.h"
#include "string.h"
int pre (char);
int main()
{
    char x[20];
    char opd[20],opr[20];
    int i,j=-1,k=-1,a,b;
    printf("\nEnter infix expression: ");
    scanf("%s",x);
    for(i=0;i<strlen(x);i++)
    {
        if(x[i]>=48 && x[i]<=57)
        {
            j++;
            opd[j]=x[i];
        }
        else
        {
            if(k==-1)
            {
                k++;
                opr[k]=x[i];
            }
            else
            {
                a=pre(x[i]);
                b=pre(opr[k]);
                while(k>=0 && a<=b)
                {
                    j++;
                    opd[j]=opr[k];
                    k--;
                    if(k== -1)
                    break;
                    b=pre(opr[k]);
                }
                    k++;
                    opr[k]=x[i];
            }
        }
    }
    while(k>=0)
    {
        j++;
        opd[j]=opr[k];
        k--;
    }
    for(i=0;i<=j;i++)
        printf("%c ",opd[i]);
}
int pre (char x)
{
    switch(x)
    {
        case '+':
        case '-':
            return 5;
        case '*':
        case '/':
        case '%':
            return 6;
    }
} 
            
// WAP to input your mark and display your grade.

#include "stdio.h"
int main()
{
        int sub1,sub2,sub3,sub4,sub5;
        float total,avg;
        printf("Enter the each subject mark: ");
        scanf("%d%d%d%d%d",&sub1,&sub2,&sub3,&sub4,&sub5);

        total = sub1+sub2+sub3+sub4+sub5;
        printf("\ntotal is: %.2f ", total);

        avg = total/5;
        printf("\navg mark is: %.2f ", avg);

        if(avg <= 100 && avg >= 90)
        {
                printf("\ngrade = O");
        }
        else
        if(avg <= 89&& avg >= 80)
        {
                printf("\ngrade = E");
        }
        else
        if(avg <= 79 && avg >= 70)
        {
                printf("\ngrade = A");
        }
        else
        if(avg <= 69 && avg >= 60)
        {
                printf("\ngrade = B");
        }
        else
        if(avg <= 59 && avg >= 50)
        {
                printf("\ngrade = C");
        }
        else
        if(avg <= 49 && avg >= 40)
        {
                printf("\ngrade = D");
        }
        else
        {
                printf("\ngrade = F");
        }
        return 0;

}

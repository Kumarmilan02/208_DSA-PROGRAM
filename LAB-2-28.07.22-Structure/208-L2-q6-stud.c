//WAP TO STORE INFORMATON OF 10 STUDENTS USING STRUCTURE.

#include"stdio.h"
#include "stdlib.h"
#include"string.h"
        struct student
        {
                int roll;
                char name[20];
                char branch[10];
                float cgpa;
        };
int main()
{
        struct student m[20];
        int i;
        for(i=0;i<10;i++)
        {
                printf("\nEnter roll:");
                scanf("%d",&m[i].roll);
                printf("\nEnter name: ");
                scanf("%s",m[i].name);
                printf("\nEnter branch: ");
                scanf("%s",m[i].branch);
                printf("\nEnter cgpa: ");
                scanf("%f",&m[i].cgpa);
        }
        printf("Display imformation:  \n");
        for(i=0;i<10;i++)
        {
                printf("\nRoll no.: %d",m[i].roll);
                printf("\nName: %s",m[i].name);
                printf("\nBranch: %s",m[i].branch);
                printf("\ncgpa: %f",m[i].cgpa);
                printf("\n");
        }
       return 0;
}


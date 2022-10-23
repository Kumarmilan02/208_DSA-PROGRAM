//WAP TO CALCULATE THE SUBJECT WISE TOTAL AND DISPLAY THEM. 

#include<stdio.h>
struct student
{
    char name[20];
    int roll;
    int marks[5];
    int total;
};
int main()
{
    struct student s[5];
    int i,j;
    printf("Enter student details with marks in 5 subject;\n");
    for(i=0;i<5;i++)
    {
        printf("FOR STUDENT: %d\n",i+1);        
        printf("Enter Name: ");
        scanf("%s", s[i].name);
        printf("Enter roll number:");
        scanf("%d",&s[i].roll);
        s[i].total=0;
        for(j=0;j<5;j++)
        {
            printf("Marks in Subject %d:",j+1);
            scanf("%d", &s[i].marks[j]);
            s[i].total=s[i].total+s[i].marks[j];
        }
    }
    printf("=========Displaying students Information:==========\n");
    for (i = 0; i < 5; ++i)
    {
        printf("FOR STUDENT %d\n",i+1);
        printf("Name: ");
        puts(s[i].name);
        printf("roll number:%d\n",s[i].roll);
        for(j=0;j<5;j++)
        {
            printf("Mark in Sub[%d]= %d\n",j+1,s[i].marks[j]);
        }
        printf("TOTAL MARKS IN 5 SUBJECTS IS %d\n",s[i].total);
        printf("\n");
    }
    return 0;
}

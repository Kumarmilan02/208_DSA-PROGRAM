//WAP TO CPOY THE CONTENT OF ONE STRUCTURE VARIABLE IN ANOTHER AND COMPARE WHEATHER SAME OR NOT.

#include <stdio.h>
struct student{
    int roll;
    char name[100];
    float total;
    float prcnt;
};

int main(){
    struct student s1,s2;
    printf("ENTER NAME OF THE STUDENT: ");
    scanf("%[^\n]s",s1.name);
    printf("ENTER ROLL OF THE STUDENT: ");
    scanf("%d",&s1.roll);
    printf("ENTER TOTAL MARKS OF THE STUDENT out of 500: ");
    scanf("%f",&s1.total);
    s1.prcnt=s1.total/5;
    s2=s1;
    if((s2.roll==s1.roll)&&(s2.total==s1.total)){
        printf("\n STRUCTURE COPIED SUCCESSFULLY. ");

    }
    printf("\n \n DISPLAY");
    printf("\n ROLL: %d",s2.roll);
    printf("\n NAME: %s",s2.name);
    printf("\n TOTAL MARKS: %f",s2.total);
    printf("\n PERCENTAGE: %f ",s2.prcnt);
    return 0;

}

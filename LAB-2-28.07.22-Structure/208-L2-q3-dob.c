//WAP TO DECLARE A STRUCTURE CONTAINING DATE,MONTH,YEAR.FIND THE AGE OF A PERSON IF DOB AND CURRENT DATE IS GIVEN.

#include <stdio.h>
struct DATE
{
int day;
int month;
int year;
};
int main()
{
struct DATE current;
struct DATE dob;
printf("Enter current date in format (day/month/year):\n");
scanf("%d%d%d",&current.day,&current.month,&current.year);
printf("Enter your date of birth in format(day/month/year):\n");
scanf("%d%d%d",&dob.day,&dob.month,&dob.year);
printf("Today's date:%d/%d/%d\t\n",current.day,current.month,current.year);
printf("Your date of birth is %d/%d/%d\t\n",dob.day,dob.month,dob.year);
if(current.day<dob.day)
{
current.day=current.day+30;
current.month=current.month-1;
}
if(current.month<dob.month)
{
current.month=current.month+12;
current.year=current.year-1;
}
printf("YOUR PERSENT AGE IS :%d year %d month %d days",current.year- dob.year,current.month-dob.month,current.day-dob.day);
return 0;
}
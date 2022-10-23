//. Write a menu driven program to input a number and display your choice.
// 1)One 2)Two  3)Three  4)four  5)quit

#include <stdio.h>

int main()
{
    int i;
    printf("MENU:\n");
    printf("1:ONE\n");
    printf("2:TWO\n");
    printf("3:THREE\n");
    printf("4:EXIT\n");
    printf("enter your choise:");
    scanf("%d",&i);
    switch(i){
        case 1:{
            printf("you selected one:");
            break;
        }
        case 2:{
            printf("you selected two");
            break;
        }
        case 3:{
            printf("you selected three");
            break;
        }
        case 4:{
            printf("you selected exit:");
            break;
        }
        default:
        {
            printf("sorry wrong option:");
            break;
        }
    }
    return 0;
}
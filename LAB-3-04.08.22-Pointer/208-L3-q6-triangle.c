//WAP to compute the lengths of three sides of a triangle formed by three points whose co-ordinates are given.
// Check whether the triangle can be formed or not. Then compute the area of a triangle.
// Next take a point as input from the user and check whether it is inside or outside the triangle. 
//(Hint: the representation of the vertices of the triangle as pointers.)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
void enter(int *x){
    printf("\n ENTER X and Y : ");
    scanf("%d%d",x,x+1);
    printf("COORDINATE: %d,%d",*x,*(x+1));
}
float len(int *p1,int* p2){
    float length=sqrt(pow(((*p2)-(*p1)),2)+pow((*(p2+1)-*(p1+1)),2));
    return length;
}
void check(float a,float b,float c){
    if((a+b>c)&&(b+c>a)&&(a+c>b)){
        printf("\n TRIANGLE IS VALID. ");
    }
    else{
        printf("\n TRIANGLE INVALID. ");

    }
}
float area(int *x,int* y,int *z){
    return abs(((*x)*((*(y+1)-*(z+1))) + (*y)*((*(z+1)-*(x+1)))+ (*z)*((*(x+1)-*(y+1))))/2.0);
}
void pchk(int *x,int* y,int *z,int *p){
    float A,a2,a3,a4;
    A=area(x,y,z);
    printf("\n AREA: %f",A);
    a2=area(x,y,p);
    printf("\n AREA: %f",a2);
    a3=area(x,p,z);
    printf("\n AREA: %f",a3);
    a4=area(p,y,z);
    printf("\n AREA: %f",a4);
    if(A==(a3+a2+a4)){
        printf("\n POINT INSIDE.");
    }
    else{
        printf("\n POINT OUTSIDE.");
    }
}
int main(){
    int *p,*q,*r,*a;

    printf("\n ENTER THREE VERTICES: ");
    p=(int*)malloc(2*sizeof(int));
    q=(int*)malloc(2*sizeof(int));
    r=(int*)malloc(2*sizeof(int));
    enter(p);
    enter(q);
    enter(r);
    float s1,s2,s3;
    s1=len(p,q);
    s2=len(r,q);
    s3=len(p,r);
    check(s1,s2,s3);
    printf("\n AREA: %f",area(p,q,r));
    printf("\n ENTER POINT TO CHECK: ");
    a=(int*)malloc(2*sizeof(int));
    enter(a);
    pchk(p,q,r,a);
    return 0;
}


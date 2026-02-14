#include<stdio.h>
int swap(int a,int b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
    return 0;
}
int main()
{
    int x,y,z;
    printf("Enter the value of x : ");
    scanf("%d",&x);
    printf("Enter the value of y : ");
    scanf("%d",&y);
    z=swap(x,y);
    printf("x : %d \n y : %d \n",x,y);
    return 0;
}

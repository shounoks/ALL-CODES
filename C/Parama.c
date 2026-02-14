#include<stdio.h>
int main()
{
    int a[5];
    int i;
    printf("Enter the elements of the array \n");

    for(i=0;i<5;i++)
    {
        printf("[%d] = ",i);

       scanf("%d",&a[i]);
    }

    printf("\n Printing array : \n");
    for(i=0;i<5;i++)
    {
        printf(" %d  ",a[i]);
    }
    return 0;
}

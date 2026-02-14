#include<stdio.h>
int main()
{
    int array_size;
    printf("Enter the size of array : ");
    scanf("%d",&array_size);

    int ar[array_size];

    printf("Enter the numbers : \n");
    for(int i=0;i<array_size;i++)
    {
        printf("[%d] = ",i);
        scanf("%d",&ar[i]);
    }
    printf("Previous Array  : \n");
    for(int i=0;i<array_size;i++)
    {
        printf(" %d ",ar[i]);
    }

    printf("Array after reversing without another array : \n");
    
    //Main Logic
    for(int i=0;i<array_size;i++)
    {
        int temp =ar[i];
        ar[i]=ar[array_size-1-i];
        ar[array_size-1-i] = temp;
    }

    printf("New Array : \n");

    for(int i=0;i<array_size;i++)
    {
        printf(" [%d] = %d  \n",i,ar[i]);
    }
    return 0;



}
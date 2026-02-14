#include<stdio.h>
int main()
{
    int ar[]={77,42,35,12,101,5};
    int temp;
    int x = sizeof(ar)/sizeof(ar[2]);
    printf("Size : %d \n",x);

    printf("Original Array: ");
    for(int i =0; i<x; i++)
    {
        printf("%d ",ar[i]);
    }
    printf("\n");

    for(int i=0; i<x; i++)
    {
        for(int j=0; j<x; j++)
        {
            if(ar[i]<ar[j])
            {
                temp=ar[i];
                ar[i]=ar[j];
                ar[j]=temp;
            }
        }
    }
    printf("After sorting: ");
    for(int i =0; i<x; i++)
    {
        printf("%d ",ar[i]);
    }
    printf("\n");
    return 0;
}















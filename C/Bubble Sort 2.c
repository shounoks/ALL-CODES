#include<stdio.h>
int main()
{
    int ar[]={77,42,35,12,101,5};
    int x = sizeof(ar)/sizeof(ar[2]);
    printf("Size : %d \n",x);

    //Printing original value
    printf("Elements of Array : ");
    for(int i =0; i<x; i++)
    {
        printf("%d ",ar[i]);
    }
    printf("\n");

    //Sorting
    for(int i=0; i<x-1; i++)
    {
        for(int j=0; j<x-i-1; j++)
        {
            if(ar[j]>ar[j+1])
            {
                int temp = ar[j];
                ar[j] = ar[j+1];
                ar[j+1] = temp;
            }
        }
    }

    printf("Sorted Array : ");
    for(int i =0; i<x; i++)
    {
        printf("%d ",ar[i]);
    }
    printf("\n");

    return 0;
}








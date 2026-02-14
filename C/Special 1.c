#include<stdio.h>
int find_min(int ar[],int n)
{
    int min = ar[0];
    for(int i=0;i<n;i++)
    {
        if(ar[i]<min)
        {
            min = ar[i];
        }
    }
    printf("Min is : %d\n",min);
    return min;
}
int main()
{
    int ar_size;
    printf("Enter the size of array : ");
    scanf("%d",&ar_size);
    int array1[ar_size];
    printf("Enter the elements of array : \n");
    for(int i =0 ;i<ar_size;i++)
    {
        printf("[%d] = ",i);
        scanf("%d",&array1[i]);
    }
    find_min(array1,ar_size);

    return 0;
}

#include<stdio.h>

int swaap(int ara[],int i,int j)
{
    int temp = ara[i];
    ara[i] = ara[j];
    ara[j] = temp;
}

int main()
{
    int n;
    printf("Enter the size of array : ");
    scanf("%d",&n);

    int ar[n];
    printf("Enter the elements of the array : \n");
    for(int i=0;i<n;i++)
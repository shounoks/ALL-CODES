#include<stdio.h>
int binsee(int ara[],int low,int high,int search)
{
    if(low<=high){
        int mid = (low+high)/2;

        if(ara[mid]==search)
            {
                return  mid;
            }
        else if(ara[mid]<search)
           {
                return binsee(ara,mid+1,high,search);
           }
        else
            {
                return binsee(ara,low,mid-1,search);
            }
    }
    return -1;
}

int  main()
{
    int size,searched;

    printf("Enter the size of array : ");
    scanf("%d",&size);

    int ar[size];

    printf("Enter the sorted elements for the array : \n");

    for(int i = 0;i<size;i++)
    {
        printf("[%d] = ",i);
        scanf("%d",&ar[i]);
    }
    printf("Enter the number you want to search : ");
    scanf("%d",&searched);

    int result = binsee(ar,0,size-1,searched);

    if(result == -1)
        printf("Not found! ");
    else
        printf("%d is found at %d \n",searched,result);

return 0;


}

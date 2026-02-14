#include<stdio.h>
int binse(int ara[],int size,int search)
{
    int low,high,mid;
    low = 0;
    high = size-1;

    while(low<=high)
    {
        mid = (low+high)/2;

        if (ara[mid]==search){
             return mid;
        }

        else if(ara[mid]<search)
        {
            low = mid+1;
        }

        else
        {
            high = mid -1;
        }
    }

    return -1;
}


int main()
{
    int ar_size,searched;

    printf("Enter the size of the array :  ");
    scanf("%d",&ar_size);

    int ar[ar_size];

    printf("Enter the elements of the array : \n");
    for(int i =0;i<ar_size;i++)
    {
        printf("[%d] = ",i);
        scanf("%d",&ar[i]);
    }
    printf("Enter the elements you want to search : ");
    scanf("%d",&searched);


    int result = binse(ar,ar_size,searched);

    if(result ==  -1 )
        {
            printf("Not found! ");
        }
    else
        {
            printf("%d is found at index %d \n",searched,result);
        }

    return 0;

}

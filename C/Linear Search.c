#include<stdio.h>
int main()
{
    int array_size;
    printf("Enter the size of array: ");
    scanf("%d", &array_size);

    int ar[array_size];
    printf("Enter the values of array: \n");

    for(int i=0; i<array_size; i++)
    {
        printf("[%d] = ",i);
        scanf("%d", &ar[i]);
    }
    int searched_number;
    int found= -1;
    printf("Enter the number to search: ");
    scanf("%d",&searched_number);

    for(int i=0;i<array_size;i++)
    {
        if(ar[i]== searched_number)
        {
            found = i;
            break;
        }
    }

    if(found== -1)
    {
        printf("\nNot Found.\n");
    }
    else
    {
        printf("\n%d is found at index %d.\n", searched_number,found);
    }

    return 0;
}










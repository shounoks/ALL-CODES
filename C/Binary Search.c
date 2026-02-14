#include <stdio.h>

int main()
{
    int array_size;
    printf("Enter the size of array: ");
    scanf("%d", &array_size);

    int ar[array_size];
    printf("Enter the values of array: \n");
    for (int i = 0; i < array_size; i++)
    {
        printf("[%d] = ", i);
        scanf("%d", &ar[i]);
    }


    for (int i = 0; i < array_size; i++)
        {
        for (int j = 0; j < array_size; j++)
        {
            if (ar[i] < ar[j])
            {
                int temp = ar[i];
                ar[i] = ar[j];
                ar[j] = temp;
            }
        }
    }


    printf("\nSorted Array: ");

    for (int k = 0; k < array_size; k++)
    {
        printf("%d  ", ar[k]);
    }

    int searched_number;
    printf("\nEnter the number to search: ");
    scanf("%d", &searched_number);

    int low = 0, high = array_size - 1;
    int found = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (ar[mid] == searched_number)
        {
            found = mid;
            break;
        }
        else if (ar[mid] < searched_number)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (found == -1)
    {
        printf("\nNot Found.\n");
    }
    else
    {
        printf("\n%d is found at index %d.\n", searched_number, found);
    }

    return 0;
}










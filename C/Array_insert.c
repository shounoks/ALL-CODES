
#include<stdio.h>
int main()
{
    int total_array_size;
    printf("Enter the Total array size : ");
    scanf("%d",&total_array_size);
    int ar[total_array_size];

    int index;
    int element;
    int current_array_size;

    printf("Enter the size of array : ");
    scanf("%d",&current_array_size);

    for(int i=0;i<current_array_size;i++)
    {
        printf("[%d] = ",i);
        scanf("%d",&ar[i]);
    }

    printf("Array before insirtion : \n");
    for(int i=0;i<current_array_size;i++)
    {
        printf("[%d]= %d \n",i,ar[i]);
    }

    // Insertioin

    printf("Enter the element you want to insert in the array : ");
    scanf("%d",&element);

    printf("Enter the index you want to insert %d : ",element);
    scanf("%d",&index);

    if(current_array_size>=total_array_size)
    {
        printf("There is no free space in the array ");
        return 1;
    }

    else
    {
        for(int i= current_array_size-1; i>=index-1; i--)
        {
            ar[i+1] = ar[i];
        }
        ar[index-1] = element;
        current_array_size++;
    }

    printf("Array after inserting %d in %d th index  : \n",element,index);

    for(int i=0;i<current_array_size;i++)
    {
        printf("[%d] = %d\n",i,ar[i]);
    }

    return 0;


}

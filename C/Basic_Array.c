#include<stdio.h>
int main()
{
    int n;
    
    printf("Enter the size of array :\n");
    scanf("%d",&n);
    int ar[n];

    for(int i=0;i<n;i++)
    {
        printf("[%d] = ",i);
        scanf("%d",&ar[i]);
    }


    //Sum and Mean
    int sum=0;
    float avg;


    for(int i=0;i<n;i++)
    {
        sum=sum+ar[i];
    }

    avg= (float)sum / n;

    printf("Sum is : %d\n",sum);
    printf("Mean is : %.3f\n",avg);

    //Reverse an array
    printf("Array in reverse :\n");
    for(int i=n-1;i>=0;i--)
    {
        printf("%d  ",ar[i]);
    }
    printf("\n");

    //Maximum & minimum

    int max_num = ar[0];
    int min_num = ar[0];
    //Max number
    for(int i=0;i<n;i++)
    {
        if(max_num<ar[i])
        {
            max_num = ar[i];
        }
    }

    //Min Number
    for(int i=0;i<n;i++)
    {
        if(min_num>ar[i])
        {
            min_num = ar[i];
        }
    }

    printf("Maximum number of the array is : %d\n",max_num);
    printf("Minimum number of the array is : %d\n",min_num);

    //Linear Search 

    int search_num;
    int found=-1;
    int position;

    printf("Enter the number you want to search :  ");
    scanf("%d",&search_num);
    for(int i=0;i<n;i++)
    {
        if(search_num == ar[i])
        {
            found = ar[i];
            position = i;
            break;
        }
    }

    if(found == -1)
    {
        printf("The number you have searched is not in the array \n");
        printf("Try again with another number \n");
        while(1)
        {
            printf("Enter the number you want to search :  ");
            scanf("%d",&search_num);
            for(int i=0;i<n;i++)
            {
                if(search_num == ar[i])
                {
                    found = ar[i];
                    position = i;
                    break;
                }
            }
            if(found != -1)
            {
                break;
            }
        }
    }
    else
    {
        printf("%d is found at %d th index of the array \n",search_num,position);
    }

    //Array Sorting

    //Ascending order

    int temp_1;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(ar[i]>ar[j])
            {
                temp_1=ar[i];
                ar[i]=ar[j];
                ar[j]=temp_1;
            }
        }
    }
    printf("Array in ascending order : \n");

    for(int i=0;i<n;i++)
    {
        printf(" %d ",ar[i]);
    }
    printf("\n");

    //Descending order
    int temp_2;

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(ar[i]<ar[j])
            {
                temp_2 =ar[i];
                ar[i]= ar[j];
                ar[j]=temp_2;
            }
        }
    }
    printf("Array in descending order \n");
    for(int i=0;i<n;i++)
    {
        printf(" %d ",ar[i]);
    }
    printf("\n");

return 0;
}
#include<stdio.h>
int main()
{
    int array_size;
    printf("Enter the array size : ");
    scanf("%d",&array_size);

    int ar[array_size];
    //taking input of value of an array by using for loop and printfing them
    printf("Enter the values of the array :\n");
    //input
    for(int i =0;i<array_size;i++)
    {
        printf("[%d] = ",i);
        scanf("%d",&ar[i]);
    }
    //Showing output
    printf("Outputs : \n");

    printf("The values are :\n");
    printf("\n");

    for(int i =0; i<array_size;i++)
    {
        printf("%d ",ar[i]);
    }

    //Calculating sum & the avg of the array

    printf("\n");
    //Sum
    int sum= 0;
    for(int index = 0; index<array_size;index++)
    {
        sum =  sum + ar[index];
    }
    printf("The sum is : %d \n",sum);
    //Avg
    printf("\n");
    float avg1;
    avg1 = (float)sum/array_size;
    printf("Avg is : %.3f\n",avg1);

    //Another way to calculate the avg when the total number of the element is unknown
    int x;
    x = sizeof(ar)/sizeof(ar[0]);
    float avg2;
    avg2 = (float)sum/ x;
    printf("Avg2 is : %.4f\n",avg2);


    //Calculating maximum & minimum

    //Maximum
    printf("\n");
    int max_num = ar[0];
    for(int index =0;index<array_size;index++)
    {
        if(max_num<ar[index])
        {
            max_num = ar[index];
        }
    }
    printf("Maximum number in the array is : %d\n",max_num);

    //Minimum
    int min_num = ar[0];
    for(int index =0;index<array_size;index++)
    {
        if(min_num>ar[index])
        {
            min_num = ar[index];
        }
    }
    printf("Minimum number in the array is : %d\n",min_num);

    //Searching some element by using leniar search & show it's position
    //Input the number you want to find out
    printf("\n");
    int search_number;
    int found = -1;

    printf("Enter the number you want to search : \n");
    scanf("%d",&search_number);
    for(int indexx =0;indexx<array_size;indexx++)
    {
        if(ar[indexx]==search_number)
        {
            found = indexx;
            break;
        }
    }
    if(found == -1)
    {
        printf("%d is not found anywhere\n",search_number);
    }
    else
    {
        printf("%d is found at position : %d \n", search_number,found);
    }

    //Array sorting
        //Descinding Order
    printf("Array in descinding order :\n");
    int ii,jj,temp2;

    for(ii=0;ii<array_size;ii++)
    {
        for(jj=ii+1;jj<array_size;jj++)
        {
            if(ar[ii]<ar[jj])
            {
                temp2 = ar[ii];
                ar[ii]=ar[jj];
                ar[jj]=temp2;
            }
        }
    }
    for(int i =0;i<array_size;i++)
    {
        printf("%d ",ar[i]);
    }

    //Ascending order
    printf("\n");
    printf("Array in Ascending order : \n");
    int i,j,temp;

    for(i=0;i<array_size;i++)
    {
        for(j=i+1;j<array_size;j++)
        {
            if(ar[i]>ar[j])
            {
                temp = ar[i];
                ar[i]=ar[j];
                ar[j]=temp;
            }
        }
    }
    for(int i =0;i<array_size;i++)
    {
        printf("%d ",ar[i]);

    }
    printf("\n");




    //Showing the out put in reverse order
    printf("\n");

    printf("The elements in reverse order : \n");

    for(int iii=4;iii>=0;iii--)
    {
        printf("%d ",ar[iii]);
    }

    return 0;

}

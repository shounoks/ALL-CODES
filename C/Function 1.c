#include<stdio.h>
float find_sum_and_avg(int ara[],int n)
{
    float sum=0;

    for(int i =0;i<n;i++)
    {
        sum=sum+ara[i];
    }
    printf("Sum is : %f \n",sum);
    float Avg = sum /n;
    printf("Avg is : %.4f\n",Avg);

}
int find_max(int ara[],int n)
{
    int max = ara[0];
    for(int i=0;i<n;i++)
    {
        if(max<ara[i])
        {
            max = ara[i];
        }
    }
    return max;
}
int find_min(int ara[],int n)
{
    int min=ara[0];
    for(int i=0;i<n;i++)
    {
        if(min>ara[i])
        {
            min=ara[i];
        }
    }
    return min;
}
int find_a_num(int ara[],int n)
{
    int sea;
    printf("Enter the number you want to search : ");
    scanf("%d",&sea);
    int found =-1;
    for(int i =0;i<n;i++)
    {
        if(sea == ara[i])
        {
            found = i;
            break;
        }
    }
    return found;
}
int as_or(int ara[],int n )
{
    for(int i=0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            if(ara[i]<ara[j])
            {
                int temp = ara[i];
                ara[i]=ara[j];
                ara[j]=temp;
            }
        }
    }

    return ara[n];
}
int ds_or(int ara[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j= 0;j<n;j++)
        {
            if(ara[i]>ara[j])
            {
                int temp = ara[i];
                ara[i]=ara[j];
                ara[j]=temp;
            }
        }
    }
    return ara[n];
}
//Starting main function

int main()
{
    int n ;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    int ar[n];
    printf("Enter the values of the array : \n");
    for(int i =0;i<n;i++)
    {
        printf("[%d] = ",i);
        scanf("%d",&ar[i]);
    }

    int x = find_max(ar,n);
    printf("Max is : %d\n",x);


    int y = find_min(ar,n);
    printf("Min : %d\n",y);

    int z = find_a_num(ar,n);

    if(z ==-1)
    {
        printf("Not found!\n");
    }
    else
    {
        printf("Found at %d\n",z);
    }

    int a = find_sum_and_avg(ar,n);


    as_or(ar,n);
    printf("Printing the values of the array in ascending order : \n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",ar[i]);
    }
    printf("\n");
    ds_or(ar,n);
    printf("Printing the values of the array in descending order : \n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",ar[i]);
    }

    return 0;


}

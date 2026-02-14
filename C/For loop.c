#include<stdio.h>
int main()
{
    int shounok;
    printf("Enter the size of array: ");
    scanf("%d", &shounok);

    int i, ar[shounok];
    printf("Enter the values of array: \n");

    for(i=0; i<shounok; i++)
    {
        printf("[%d] = ", i);
        scanf("%d", &ar[i]);
    }

    int sum = 0;
    for(i=0; i<shounok; i++)
    {
        sum=sum+ar[i];
    }
    printf("\n\nSum = %d\n\n", sum);


    float avg = (float)sum/shounok;
    printf("Average = %.3f\n\n", avg);



     int a, b, c;
    for(a=0; a<shounok; a++)
    {
        for(b=a+1; b<shounok; b++)
        {
            if(ar[a]>ar[b])
            {
                int temp1=ar[a];
                ar[a]=ar[b];
                ar[b]=temp1;
            }
        }
    }
    printf("Ascending Order: ");

    for(c=0; c<shounok; c++)
    {
      printf(" %d  ", ar[c]);
    }



     int p, q, r;
    for(p=0; p<shounok; p++)
    {
        for(q=p+1; q<shounok; q++)
        {
           if(ar[p]<ar[q])
           {
               int temp2=ar[p];
               ar[p]=ar[q];
               ar[q]=temp2;
           }
        }
    }
    printf("\n\nDescending Order: ");

    for(r=0; r<shounok; r++)
    {
        printf(" %d  ",ar[r]);
    }
    printf("\n\n\n");


    return 0;
}
















#include<stdio.h>
int main()
{
    int ar[1000];
    int V;
    scanf("%d",&V);
    for(int i =V;i<10000;i++)
    {
        ar[1000]= V+1;
        printf("N [%d] = %d\n",i,ar[i]);
    }
    return 0;

}

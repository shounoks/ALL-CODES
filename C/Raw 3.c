#include<stdio.h>
int main()
{
    int i, M,N,Sum=0;

    while(1)
    {
        scanf("%d",&M);
        scanf("%d",&N);

        if(M<N &&(M!=0 || M>0) && (N!=0 || N>0))
        {
            for(i=M;i<=N;i++)
            {
                Sum = Sum+i;
                printf("%d  Sum = %d ",i,Sum);
            }

        }


        else if(M>N && (M!=0 || M>0) && (N!=0 || N>0))
        {
            for(i=N;i<=M;i++)
            {
                Sum = Sum+i;
                printf("%d ",i);
            }

        }


        else if((M==0||M<0) || (N==0)||(N<0))
        {
            return 0;
        }

        printf("Sum = %d\n",Sum);

    }


}

#include<stdio.h>
int main()
{
    int ara[5]={1,2,3,4,5};
    int  *p;
    //First value
    printf("%d\n",ara[0]);
    //Pointer value
    printf("%d",*p);
    printf("\n");
    printf("%d",*p++);
    printf("\n");
    printf("%d",++*p);
    printf("\n");
    printf("%d",*(p+4));
    printf("\n");
    p = &ara[2];
    printf("\n");
    printf("%d",*(p-1));

    return 0;

}

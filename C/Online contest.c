#include<string.h>
#include<stdio.h>
int main()
{
    char ara[]="When in doubt, trust Nirob vai—and maybe attend a coding class or two.";
    int n= strcspn(ara,",..");
    printf("%d\n",n);
    return 0;

}


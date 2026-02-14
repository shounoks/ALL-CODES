
#include <stdio.h>
int main (){
    int N;
    printf("N = ");
scanf("%d", &N);
int a[N];
int sum=0,product=1;


for(int i=0;i<N;i++){
        printf("Array = {}");
        scanf("%d", &a[i]);
}

for(int i=0;i<N;i++){
        if(a[i]%2==0){
        sum=sum+a[i];
        }
}
printf("Sum of even numbers = %d\n", sum);
for(int i=0;i<N;i++){
        if(a[i]%2!=0){
            product=product*a[i];
        }
}
printf("product of odd numbers = %d\n", product);
int max =a[0];
for(int i=0;i<N;i++){
    if(a[i]>max){
    max=a[i];
                }
        }
printf("Maximum value = %d\n", max);
int min =a[0];
for(int i=0;i<N;i++){
if(a[i]<min){
min=a[i];
            }
        }
printf("Minimum value = %d\n", min);

return 0;
}

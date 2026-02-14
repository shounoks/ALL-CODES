#include<stdio.h>

void merge(int ar[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];


    for(int i = 0; i < n1; i++)
        L[i] = ar[left + i];
    for(int j = 0; j < n2; j++)
        R[j] = ar[mid + 1 + j];

    int i = 0, j = 0, k = left;


    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
            ar[k++] = L[i++];
        else
            ar[k++] = R[j++];
    }

    while(i < n1)
        ar[k++] = L[i++];

    while(j < n2)
        ar[k++] = R[j++];
}


void mergeSort(int ar[], int left, int right)
{
    if(left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(ar, left, mid);
        mergeSort(ar, mid + 1, right);

        merge(ar, left, mid, right);
    }
}

int main()
{
    int ar[] = {54, 101, 88, 19, 33, 205, 76};
    int x = sizeof(ar) / sizeof(ar[0]);
    printf("Size : %d \n", x);

    printf("Elements of Array : ");
    for(int i = 0; i < x; i++)
    {
        printf("%d ", ar[i]);
    }
    printf("\n");


    mergeSort(ar, 0, x - 1);

    printf("Sorted Array : ");
    for(int i = 0; i < x; i++)
    {
        printf("%d ", ar[i]);
    }
    printf("\n");

    return 0;
}












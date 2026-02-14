#include <stdio.h>
int main() {
    int arr[] = {10, 20, 30, 40, 50};   // An array of integers
    int *ptr = arr;                     // Pointer to the first element of the array

    // Accessing array elements using the pointer
    printf("Array elements using pointer:\n");
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d\n", i, *(ptr + i));
    }
    // Modifying array elements using the pointer
    for (int i = 0; i < 5; i++) {
        *(ptr + i) += 10;    // Adding 10 to each element
    }
    printf("\nArray elements after modification:\n");
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    return 0;
}

#include <stdio.h>

#define MAX_USERS 100          // Defining a constant with #define
#define PI 3.14159             // Defining a constant for Pi
#define SQUARE(x) ((x) * (x)) // A macro to square a number

int main() {
    // Using the constants
    printf("Max Users: %d\n", MAX_USERS);
    printf("PI value: %.5f\n", PI);

    // Using the macro to square a number
    int number = 4;
    printf("Square of %d: %d\n", number, SQUARE(number));

    // MAX_USERS and PI cannot be modified as they are constants
    // MAX_USERS = 200; // Uncommenting this line will cause an error

    return 0;
}

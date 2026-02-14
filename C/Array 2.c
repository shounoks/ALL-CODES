#include <stdio.h>

int main() {
    int arr[100], n = 0; // Array to hold elements and 'n' is the current size
    int choice, pos, element, i, found;

    while (1) {  // Infinite loop
        printf("\nMenu:\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Search Element\n");
        printf("4. Update Element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Insert Element
                printf("Enter the position to insert (1 to %d): ", n+1);
                scanf("%d", &pos);
                if (pos > 0 && pos <= n+1) {
                    printf("Enter the element to insert: ");
                    scanf("%d", &element);
                    for (i = n; i >= pos; i--) {
                        arr[i] = arr[i-1];
                    }
                    arr[pos-1] = element;
                    n++;
                    printf("Element inserted successfully!\n");
                } else {
                    printf("Invalid position!\n");
                }
                break;

            case 2:
                // Delete Element
                printf("Enter the position to delete (1 to %d): ", n);
                scanf("%d", &pos);
                if (pos > 0 && pos <= n) {
                    for (i = pos-1; i < n-1; i++) {
                        arr[i] = arr[i+1];
                    }
                    n--;
                    printf("Element deleted successfully!\n");
                } else {
                    printf("Invalid position!\n");
                }
                break;

            case 3:
                // Search Element
                printf("Enter the element to search: ");
                scanf("%d", &element);
                found = 0;
                for (i = 0; i < n; i++) {
                    if (arr[i] == element) {
                        printf("Element found at position %d\n", i+1);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Element not found!\n");
                }
                break;

            case 4:
                // Update Element
                printf("Enter the position to update (1 to %d): ", n);
                scanf("%d", &pos);
                if (pos > 0 && pos <= n) {
                    printf("Enter the new element: ");
                    scanf("%d", &element);
                    arr[pos-1] = element;
                    printf("Element updated successfully!\n");
                } else {
                    printf("Invalid position!\n");
                }
                break;

            case 5:
                // Exit
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;

}

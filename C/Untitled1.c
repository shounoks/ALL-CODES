#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a Student node in a BST
typedef struct Student {
    char name[50];
    int id;
    float mark1;
    float mark2;
    struct Student* left;
    struct Student* right;
} Student;

// Root of the tree
Student* root = NULL;

// Function to create a new student node
Student* createStudent() {
    Student* newStudent = (Student*)malloc(sizeof(Student));

    printf("Name: ");
    scanf("%s", newStudent->name);
    printf("ID: ");
    scanf("%d", &newStudent->id);
    printf("Mark for subject 1: ");
    scanf("%f", &newStudent->mark1);
    printf("Mark for subject 2: ");
    scanf("%f", &newStudent->mark2);

    newStudent->left = newStudent->right = NULL;
    return newStudent;
}

// Insert a student into the BST based on ID
Student* insertStudent(Student* root, Student* newStudent) {
    if (root == NULL) return newStudent;

    if (newStudent->id < root->id) {
        root->left = insertStudent(root->left, newStudent);
    } else {
        root->right = insertStudent(root->right, newStudent);
    }
    return root;
}

// Calculate grade from average
void calculateGrade(float avg) {
    if (avg >= 85) {
        printf("Grade: A\n");
    } else if (avg >= 70) {
        printf("Grade: B\n");
    } else if (avg >= 50) {
        printf("Grade: C\n");
    } else {
        printf("Grade: D\n");
    }
}

// Search for a student by ID in the BST
void searchStudent(Student* root, int id) {
    if (root == NULL) {
        printf("Student with ID %d not found.\n", id);
        return;
    }

    if (id == root->id) {
        printf("Name: %s\n", root->name);
        printf("ID: %d\n", root->id);
        printf("Subject 1: %.2f\n", root->mark1);
        printf("Subject 2: %.2f\n", root->mark2);
        float avg = (root->mark1 + root->mark2) / 2;
        printf("Average: %.2f\n", avg);
        calculateGrade(avg);
    } else if (id < root->id) {
        searchStudent(root->left, id);
    } else {
        searchStudent(root->right, id);
    }
}

// In-order traversal to display all students sorted by ID
void displayStudents(Student* root) {
    if (root != NULL) {
        displayStudents(root->left);
        printf("\nName: %s\n", root->name);
        printf("ID: %d\n", root->id);
        printf("Subject 1: %.2f\n", root->mark1);
        printf("Subject 2: %.2f\n", root->mark2);
        float avg = (root->mark1 + root->mark2) / 2;
        printf("Average: %.2f\n", avg);
        calculateGrade(avg);
        displayStudents(root->right);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Student\n");
        printf("2. Search Student by ID\n");
        printf("3. Display All Students\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            Student* s = createStudent();
            root = insertStudent(root, s);
        } else if (choice == 2) {
            int id;
            printf("Enter ID to search: ");
            scanf("%d", &id);
            searchStudent(root, id);
        } else if (choice == 3) {
            if (root == NULL) {
                printf("No students added yet.\n");
            } else {
                displayStudents(root);
            }
        } else if (choice == 4) {
            printf("Exiting program.\n");
            break;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}


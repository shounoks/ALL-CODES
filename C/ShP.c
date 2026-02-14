#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[50];
    int id;
    float mark1;
    float mark2;
    struct Student* next;
} Student;

Student* head = NULL;

void addStudent() {
    Student* newStudent = (Student*)malloc(sizeof(Student));

    printf("Name: ");
    scanf("%s", newStudent->name);
    printf("ID: ");
    scanf("%d", &newStudent->id);
    printf("Mark for subject 1: ");
    scanf("%f", &newStudent->mark1);
    printf("Mark for subject 2: ");
    scanf("%f", &newStudent->mark2);

    newStudent->next = head;
    head = newStudent;

}

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

void searchStudentByID() {
    int searchID;
    printf("Enter student ID to search: ");
    scanf("%d", &searchID);

    Student* current = head;
    while (current != NULL) {
        if (current->id == searchID) {
            printf("Name: %s\n", current->name);
            printf("ID: %d\n", current->id);
            printf("Subject 1: %.2f\n", current->mark1);
            printf("Subject 2: %.2f\n", current->mark2);
            float avg = (current->mark1 + current->mark2) / 2;
            printf("Average: %.2f\n", avg);
            calculateGrade(avg);
            return;
        }
        current = current->next;
    }
    printf("Student with ID %d not found.\n", searchID);
}

void displayAllStudents() {
    Student* current = head;
    if (current == NULL) {
        printf("No students to display.\n");
        return;
    }

    while (current != NULL) {
        printf("\nName: %s\n", current->name);
        printf("ID: %d\n", current->id);
        printf("Subject 1: %.2f\n", current->mark1);
        printf("Subject 2: %.2f\n", current->mark2);
        float avg = (current->mark1 + current->mark2) / 2;
        printf("Average: %.2f\n", avg);
        calculateGrade(avg);
        current = current->next;
    }
}

int main() {
    int choice;
    while (1) {
        printf("1. Add \n");
        printf("2. Search Student\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addStudent();
            break;
        case 2:
            searchStudentByID();
            break;
        case 3:
            displayAllStudents();
            break;
        case 4:
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid choice. Try again.\n");
        }
    }
}

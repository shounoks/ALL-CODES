#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[50];
    int id;
    float cgpa;
    int semester;
    char section;
    struct Student* prev;
    struct Student* next;
} Student;

Student* head = NULL;

Student* createStudent(char name[], int id, float cgpa, int semester, char section) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    strcpy(newStudent->name, name);
    newStudent->id = id;
    newStudent->cgpa = cgpa;
    newStudent->semester = semester;
    newStudent->section = section;
    newStudent->prev = NULL;
    newStudent->next = NULL;
    return newStudent;
}

void insertAtBeginning(char name[], int id, float cgpa, int semester, char section) {
    Student* newStudent = createStudent(name, id, cgpa, semester, section);
    if (head != NULL) {
        newStudent->next = head;
        head->prev = newStudent;
    }
    head = newStudent;
}

void insertAtEnd(char name[], int id, float cgpa, int semester, char section) {
    Student* newStudent = createStudent(name, id, cgpa, semester, section);
    if (head == NULL) {
        head = newStudent;
        return;
    }
    Student* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newStudent;
    newStudent->prev = temp;
}

void insertAtPosition(char name[], int id, float cgpa, int semester, char section, int position) {
    if (position <= 1) {
        insertAtBeginning(name, id, cgpa, semester, section);
        return;
    }
    Student* newStudent = createStudent(name, id, cgpa, semester, section);
    Student* temp = head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        insertAtEnd(name, id, cgpa, semester, section);
        return;
    }
    newStudent->next = temp->next;
    newStudent->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newStudent;
    temp->next = newStudent;
}

void displayForward() {
    Student* temp = head;
    while (temp != NULL) {
        printf("%s %d %.2f %d %c\n", temp->name, temp->id, temp->cgpa, temp->semester, temp->section);
        temp = temp->next;
    }
}

void displayBackward() {
    if (head == NULL) return;
    Student* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    while (temp != NULL) {
        printf("%s %d %.2f %d %c\n", temp->name, temp->id, temp->cgpa, temp->semester, temp->section);
        temp = temp->prev;
    }
}

void deleteFromBeginning() {
    if (head == NULL) return;
    Student* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    free(temp);
}

void deleteFromEnd() {
    if (head == NULL) return;
    Student* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;
    free(temp);
}

void deleteFromPosition(int position) {
    if (head == NULL) return;
    if (position == 1) {
        deleteFromBeginning();
        return;
    }
    Student* temp = head;
    for (int i = 1; temp != NULL && i < position; i++) {
        temp = temp->next;
    }
    if (temp == NULL) return;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
}

Student* searchStudent(int id) {
    Student* temp = head;
    while (temp != NULL) {
        if (temp->id == id)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

int countStudents() {
    int count = 0;
    Student* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    insertAtBeginning("Alice", 101, 3.8, 3, 'A');
    insertAtEnd("Bob", 102, 3.5, 4, 'B');
    insertAtPosition("Charlie", 103, 3.9, 2, 'C', 2);

    printf("List (Forward):\n");
    displayForward();

    printf("\nList (Backward):\n");
    displayBackward();

    printf("\nDeleting from beginning...\n");
    deleteFromBeginning();
    displayForward();

    printf("\nTotal students: %d\n", countStudents());

    Student* found = searchStudent(102);
    if (found) printf("\nFound: %s\n", found->name);
    else printf("\nStudent not found\n");

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[50];
    int id;
    float mark1;
    float mark2;
    struct Student* left;
    struct Student* right;
} Student;

Stu* root = NULL;

Student* createStudent() {
    Student* newStudent

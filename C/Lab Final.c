#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct employee
{
    int employee_id;
    char name[50];
    char designation[60];
    int mobile_number;
    float salary;
    struct employee *next;
}
employee;

employee *head=NULL;

void addNewEmployee()
{
    employee *newemployee=(employee*)malloc(sizeof(employee));

printf("ID:");
scanf("%d",&newemployee->employee_id);
printf("Name:");
scanf("%s",newemployee->name);
printf("Designation:");
scanf("%s",newemployee->designation);
printf("Mobile Number:");
scanf("%d",&newemployee->mobile_number);
printf("Salary:");
scanf("%f",&newemployee->salary);

newemployee->next = head;
    head = newemployee;

}

void viewEmployee() {
    employee* current = head;
    if (current == NULL) {
        printf("No Employees to display.\n");
        return;
    }

    while (current != NULL) {
        printf("ID: %d\n", current->employee_id);
        printf("Name: %s\n", current->name);
        printf("Designation: %s\n", current->designation);
        printf("Mobile Number: %d\n", current->mobile_number);
        printf("Salary: %.2f\n", current->salary);
        current = current->next;
    }
}

void searchEmployeeByID()
 {
    int searchID;
    printf("Enter Employee ID to search: ");
    scanf("%d", &searchID);
    employee* current = head;
    while (current != NULL)
        {
        if(current->employee_id == searchID)
            {
            printf("ID:%d\n",current->employee_id);
            printf("Name:%s\n",current->name);
            printf("Designation: %s\n",current->designation);
            printf("Mobile Number: %d\n",current->mobile_number);
            printf("Salary:%.2f\n",current->salary);
            return;
        }
        current = current->next;
    }
    printf("Employee with ID %d not found.\n", searchID);

 }

int main()
{
    int choice;
    while (1)
        {
        printf("1. Add New Employee \n");
        printf("2. View Employee\n");
        printf("3. Search Employees By ID\n");
        printf("4. Remove Employee \n");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            addNewEmployee();
            break;
        case 2:
            viewEmployee();
            break;
        case 3:
            searchEmployeeByID();
            break;
        case 4:
            printf("Exiting program.\n");
        }
        return 0;
        }
}












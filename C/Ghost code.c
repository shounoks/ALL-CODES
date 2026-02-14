#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define MAX_ADMINS 2
#define MAX_REPORT_LENGTH 1000

// Employee structure definition
typedef struct {
    int emp_id;
    char name[50];
    double salary;
    double bonus;
    int working_hours;
    char password[20];
    char phone[12];
    char designation[30];
    char report[MAX_REPORT_LENGTH];
    char bonus_or_cut_reason[100];
} Employee;

// Admin structure definition
typedef struct {
    int admin_id;
    char name[50];
    char password[20];
    char phone[12];
} Admin;

// Global variables
Employee employees[MAX_EMPLOYEES];
Admin admins[MAX_ADMINS];
int employeeCount = 0;
int adminCount = 0;

// Function prototypes
void registerEmployee();
void registerAdmin();
void adminLogin();
void employeeLogin();
void adminMenu(Admin *admin);
void employeeMenu(Employee *emp);
void viewEmployeeDetails(Employee *emp);
void updateEmployeeSalary(Employee *emp, double new_salary);
void addBonus(Employee *emp, int hours_worked);
void calculateProfit(double total_income);
void searchEmployee(int emp_id, const char *name);
void deleteEmployee(int emp_id);
int validatePhoneNumber(const char *phone);
void clearBuffer();

// Utility function to clear input buffer
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Main function
int main() {
    int choice;
    while (1) {
        printf("\nEmployee Management System\n");
        printf("1. Admin Login\n2. Employee Login\n3. Register Employee\n4. Register Admin\n5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearBuffer();
            continue;
        }
        clearBuffer();

        switch (choice) {
            case 1:
                adminLogin();
                break;
            case 2:
                employeeLogin();
                break;
            case 3:
                registerEmployee();
                break;
            case 4:
                registerAdmin();
                break;
            case 5:
                printf("Exiting system.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

// Register new employee
void registerEmployee() {
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("Employee registration limit reached.\n");
        return;
    }

    Employee emp;
    emp.emp_id = employeeCount + 1;

    printf("Enter Employee Name: ");
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = '\0';

    printf("Set Password: ");
    fgets(emp.password, sizeof(emp.password), stdin);
    emp.password[strcspn(emp.password, "\n")] = '\0';

    while (1) {
        printf("Enter 11-digit Phone Number: ");
        fgets(emp.phone, sizeof(emp.phone), stdin);
        emp.phone[strcspn(emp.phone, "\n")] = '\0';
        if (validatePhoneNumber(emp.phone)) break;
        printf("Invalid Phone number! Must be 11 digits.\n");
    }

    emp.salary = 0; // Set salary to 0 initially; admin will set it
    emp.bonus = 0;
    emp.working_hours = 0;
    emp.bonus_or_cut_reason[0] = '\0';
    emp.report[0] = '\0';

    employees[employeeCount++] = emp;
    printf("Employee registered successfully with ID: %d\n", emp.emp_id);
}

// Register new admin
void registerAdmin() {
    if (adminCount >= MAX_ADMINS) {
        printf("Admin registration limit reached.\n");
        return;
    }

    Admin admin;
    admin.admin_id = adminCount + 1;

    printf("Enter Admin Name: ");
    fgets(admin.name, sizeof(admin.name), stdin);
    admin.name[strcspn(admin.name, "\n")] = '\0';

    printf("Set Password: ");
    fgets(admin.password, sizeof(admin.password), stdin);
    admin.password[strcspn(admin.password, "\n")] = '\0';

    while (1) {
        printf("Enter 11-digit Phone Number: ");
        fgets(admin.phone, sizeof(admin.phone), stdin);
        admin.phone[strcspn(admin.phone, "\n")] = '\0';
        if (validatePhoneNumber(admin.phone)) break;
        printf("Invalid Phone number! Must be 11 digits.\n");
    }

    admins[adminCount++] = admin;
    printf("Admin registered successfully. Admin ID is: %d\n", admin.admin_id);
}

// Admin login
void adminLogin() {
    int admin_id;
    char password[20];

    printf("Enter Admin ID: ");
    if (scanf("%d", &admin_id) != 1) {
        printf("Invalid input.\n");
        clearBuffer();
        return;
    }
    clearBuffer();

    printf("Enter Password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';

    for (int i = 0; i < adminCount; i++) {
        if (admins[i].admin_id == admin_id && strcmp(admins[i].password, password) == 0) {
            printf("Welcome, Admin %s\n", admins[i].name);
            adminMenu(&admins[i]);
            return;
        }
    }
    printf("Invalid Admin ID or Password.\n");
}

// Employee login
void employeeLogin() {
    int emp_id;
    char password[20];

    printf("Enter Employee ID: ");
    if (scanf("%d", &emp_id) != 1) {
        printf("Invalid input.\n");
        clearBuffer();
        return;
    }
    clearBuffer();

    printf("Enter Password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].emp_id == emp_id && strcmp(employees[i].password, password) == 0) {
            printf("Welcome, %s\n", employees[i].name);
            employeeMenu(&employees[i]);
            return;
        }
    }
    printf("Employee not found or password incorrect.\n");
}

// Admin menu actions
void adminMenu(Admin *admin) {
    int choice, emp_id;
    double salary, total_income;
    int hours_worked;

    while (1) {
        printf("\nAdmin Menu:\n1. View Employee\n2. Update Salary\n3. Add Bonus\n4. Calculate Profit\n5. Search Employee\n6. Delete Employee\n7. Logout\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            clearBuffer();
            continue;
        }
        clearBuffer();

        switch (choice) {
            case 1:
                printf("Enter Employee ID to view: ");
                scanf("%d", &emp_id);
                clearBuffer();
                for (int i = 0; i < employeeCount; i++) {
                    if (employees[i].emp_id == emp_id) {
                        viewEmployeeDetails(&employees[i]);
                        break;
                    }
                }
                break;
            case 2:
                printf("Enter Employee ID to update salary: ");
                scanf("%d", &emp_id);
                clearBuffer();
                printf("Enter new Salary: ");
                scanf("%lf", &salary);
                clearBuffer();
                for (int i = 0; i < employeeCount; i++) {
                    if (employees[i].emp_id == emp_id) {
                        updateEmployeeSalary(&employees[i], salary);
                        break;
                    }
                }
                break;
            case 3:
                printf("Enter Employee ID to add bonus: ");
                scanf("%d", &emp_id);
                clearBuffer();
                printf("Enter Working Hours: ");
                scanf("%d", &hours_worked);
                clearBuffer();
                for (int i = 0; i < employeeCount; i++) {
                    if (employees[i].emp_id == emp_id) {
                        addBonus(&employees[i], hours_worked);
                        break;
                    }
                }
                break;
            case 4:
                printf("Enter Total Income: ");
                scanf("%lf", &total_income);
                clearBuffer();
                calculateProfit(total_income);
                break;
            case 5:
                printf("Enter Employee Name to search: ");
                char name[50];
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                searchEmployee(0, name);
                break;
            case 6:
                printf("Enter Employee ID to delete: ");
                scanf("%d", &emp_id);
                clearBuffer();
                deleteEmployee(emp_id);
                break;
            case 7:
                printf("Logging out...\n");
                return;
            default:
                printf("Invalid choice.\n");
        }
    }
}

// Employee menu actions
void employeeMenu(Employee *emp) {
    int choice;
    char report[MAX_REPORT_LENGTH];

    while (1) {
        printf("\nEmployee Menu:\n1. View Details\n2. Submit Report\n3. Logout\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            clearBuffer();
            continue;
        }
        clearBuffer();

        switch (choice) {
            case 1:
                viewEmployeeDetails(emp);
                break;
            case 2:
                printf("Enter your report: ");
                fgets(report, sizeof(report), stdin);
                report[strcspn(report, "\n")] = '\0';
                strncpy(emp->report, report, MAX_REPORT_LENGTH);
                printf("Report submitted successfully.\n");
                break;
            case 3:
                printf("Logging out...\n");
                return;
            default:
                printf("Invalid choice.\n");
        }
    }
}

// View employee details
void viewEmployeeDetails(Employee *emp) {
    printf("\nEmployee Details:\n");
    printf("ID: %d\n", emp->emp_id);
    printf("Name: %s\n", emp->name);
    printf("Phone: %s\n", emp->phone);
    printf("Salary: %.2lf\n", emp->salary);
    printf("Bonus: %.2lf\n", emp->bonus);
    printf("Working Hours: %d\n", emp->working_hours);
    printf("Designation: %s\n", emp->designation);
    printf("Report: %s\n", emp->report);
}

// Update employee salary
void updateEmployeeSalary(Employee *emp, double new_salary) {
    emp->salary = new_salary;
    printf("Salary updated successfully for Employee ID %d\n", emp->emp_id);
}

// Add bonus
void addBonus(Employee *emp, int hours_worked) {
    double bonus = 0.0;

    if (hours_worked > 40) {
        bonus = emp->salary * 0.10; // 10% bonus for working over 40 hours
    }
    emp->bonus += bonus;
    printf("Bonus of %.2lf added to Employee ID %d\n", bonus, emp->emp_id);
}

// Calculate profit
void calculateProfit(double total_income) {
    double total_expense = 0.0;
    for (int i = 0; i < employeeCount; i++) {
        total_expense += employees[i].salary + employees[i].bonus;
    }
    double profit = total_income - total_expense;
    printf("Total Income: %.2lf, Total Expense: %.2lf, Profit: %.2lf\n", total_income, total_expense, profit);
}

// Search for employee by name or ID
void searchEmployee(int emp_id, const char *name) {
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].emp_id == emp_id || (name != NULL && strcmp(employees[i].name, name) == 0)) {
            viewEmployeeDetails(&employees[i]);
            return;
        }
    }
    printf("Employee not found.\n");
}

// Delete an employee
void deleteEmployee(int emp_id) {
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].emp_id == emp_id) {
            for (int j = i; j < employeeCount - 1; j++) {
                employees[j] = employees[j + 1];
            }
            employeeCount--;
            printf("Employee with ID %d deleted successfully.\n", emp_id);
            return;
        }
    }
    printf("Employee with ID %d not found.\n", emp_id);
}

// Validate phone number
int validatePhoneNumber(const char *phone) {
    if (strlen(phone) != 11) return 0;
    for (int i = 0; i < 11; i++) {
        if (phone[i] < '0' || phone[i] > '9') return 0;
    }
    return 1;
}

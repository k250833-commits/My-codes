#include <stdio.h>
#include <string.h>

typedef struct {
    int employeeID;
    char employeeName[20];
    char designation[15];
    double salary;
} data;
int i;
void displayEmployees(data D[], int n) {
    printf("\n%-12s %-20s %-20s %-10s\n",
           "Employee ID", "Employee Name", "Designation", "Salary");
    for (i = 0; i < n; ++i) {
        printf("%-12d %-20s %-20s %-10.2lf\n",
               D[i].employeeID, D[i].employeeName, D[i].designation, D[i].salary);
    }
}

void findHighestSalary(data D[], int n) {
    if (n <= 0) { printf("No employees.\n"); return; }
    double max = D[0].salary;
    for (i = 1; i < n; ++i) if (D[i].salary > max) max = D[i].salary;

    printf("\nHighest salary: %.2lf\n", max);
    printf("Employee(s) with this salary:\n");
    for (i = 0; i < n; ++i) {
        if (D[i].salary == max) {
            printf("  Name: %s | ID: %d | Designation: %s\n",
                   D[i].employeeName, D[i].employeeID, D[i].designation);
        }
    }
}

void searchEmployee(data D[], int n) {
    int choice;
    printf("\nSearch by: 1) Name  2) ID\nChoice: ");
    if (scanf("%d", &choice) != 1) { while (getchar()!='\n'); return; }
    if (choice == 1) {
        char name[20];
        printf("Enter name (case-sensitive): ");
        scanf(" %[^\n]", name);
        int found = 0;
        for (i = 0; i < n; ++i) {
            if (strcmp(D[i].employeeName, name) == 0) {
                printf("Found: ID=%d  Designation=%s  Salary=%.2lf\n",
                       D[i].employeeID, D[i].designation, D[i].salary);
                found = 1;
            }
        }
        if (!found) printf("No match found.\n");
    } else if (choice == 2) {
        int id; printf("Enter ID: "); if (scanf("%d", &id) != 1) { while (getchar()!='\n'); return; }
        int found = 0;
        for (i = 0; i < n; ++i) {
            if (D[i].employeeID == id) {
                printf("Found: Name=%s  Designation=%s  Salary=%.2lf\n",
                       D[i].employeeName, D[i].designation, D[i].salary);
                found = 1;
            }
        }
        if (!found) printf("No match found.\n");
    } else {
        printf("Invalid option.\n");
    }
}
void applyBonus(data D[], int n, double threshold, double percent) {
    for (i = 0; i < n; ++i) {
        if (D[i].salary < threshold) {
            D[i].salary = D[i].salary * (1.0 + percent / 100.0);
        }
    }
    printf("Applied %.2lf%% bonus to salaries below %.2lf\n", percent, threshold);
}
int main(void) {
    int n;
    printf("Enter number of employees: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;
    data D[n];

    printf("Enter data for %d employees:\n", n);
    for (i = 0; i < n; ++i) {
        printf("\nEmployee #%d\n", i+1);
        printf("  Name: ");     scanf(" %[^\n]", D[i].employeeName);
        printf("  ID: ");       scanf("%d", &D[i].employeeID);
        printf("  Designation: "); scanf(" %[^\n]", D[i].designation);
        printf("  Salary: ");   scanf("%lf", &D[i].salary);
    }

    int choice;
    do {
        printf("\nMenu:\n1.View all\n2.Highest salary\n3.Search\n4.Apply 10%% bonus (salary < threshold)\n5.Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) break;
        switch (choice) {
            case 1: displayEmployees(D, n); break;
            case 2: findHighestSalary(D, n); break;
            case 3: searchEmployee(D, n); break;
            case 4: {
                double threshold;
                printf("Enter threshold (e.g. 50000): ");
                if (scanf("%lf", &threshold) != 1) break;
                applyBonus(D, n, threshold, 10.0);
                break;
            }
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}


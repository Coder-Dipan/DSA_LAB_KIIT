//Q.3] Write a program to create a structure to store the information of n numbers of Employees. Employee's information includes data members : Emp-id, Name, Designation, basic_salary, hra%, da%. display the information of employees with gross salary. Use array of structure.

#include<stdio.h>
struct Employee {
    int emp_id;
    char name[50];
    char designation[50];
    float basic_salary;
    float hra;
    float da;
};

int main(){
    int n;

    printf("Enter no. of employees : ");
    scanf("%d", &n);

    struct Employee emp[n];

    //input employee information
    for(int i=0; i<n; i++){
        printf("\nEnter employee %d information : \n", i+1);
        
        printf("Employee ID : ");
        scanf("%d", &emp[i].emp_id);

        printf("Name : ");
        scanf("%s", emp[i].name);

        printf("Designation : ");
        scanf("%s", emp[i].designation);

        printf("Basic Salary : ");
        scanf("%f", &emp[i].basic_salary);

        printf("HRA (in %%) : ");
        scanf("%f", &emp[i].hra);

        printf("DA (in %%) : ");
        scanf("%f", &emp[i].da);
    }

    //Display employee infromation with gross salary
    printf("\nEmployee Details: \n");

    for(int i=0; i<n; i++){
        float hra_amount = (emp[i].hra * emp[i].basic_salary) / 100;
        float da_amount = (emp[i].da * emp[i].basic_salary) / 100;
        float gross_salary = emp[i].basic_salary + hra_amount + da_amount;

        printf("Employee %d\n", i+1);

        printf("Employee ID : %d\n", emp[i].emp_id);
        printf("Name : %s\n", emp[i].name);
        printf("Designation : %s\n", emp[i].designation);
        printf("Basic Salary : %.2f\n", emp[i].basic_salary);
        printf("HRA : %.2f%%\n", emp[i].hra);
        printf("DA : %.2f%%\n", emp[i].da);
        printf("Gross Salary : %.2f\n", gross_salary);
    }

    return 0;
}


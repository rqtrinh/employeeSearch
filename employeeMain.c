#include <string.h>
#include <stdlib.h>
#include "employee.h"
int main(void)
{
    //defined in employeeSearchOne.c
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char* nameToFind);
    PtrToEmployee searchEmployeeByPhone(const Employee table[], int sizeTable, char* phoneToFind);
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind);

    //defined by employeeTable.c
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr; //Declaration
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);

    //searchEmployeeByNumber
    //Example not found
    if (matchPtr != NULL)
        printf("Employee ID 1045 is in record %d\n", matchPtr-EmployeeTable);
    else
        printf("Employee ID 1045 is NOT found in the record\n");
    
    //searchEmployeeByName
    //Example found
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
    if (matchPtr != NULL)
        printf("Employee Tony Bobcat is in record %d\n", matchPtr-EmployeeTable);
    else
        printf("Employee Tony Bobcat is NOT found in the record\n");


    printf("\n");
    //searchEmployeeByPhone
    //Example found
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "714-555-2749");
    if (matchPtr != NULL)
        printf("Employee number 714-555-2749 is in record %d\n", matchPtr-EmployeeTable);
    else
        printf("Employee number 714-555-2749 is NOT found in the record\n");

    //Example not found
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "222-555-2749");
    if (matchPtr != NULL)
        printf("Employee number 222-555-2749 is in record %d\n", matchPtr-EmployeeTable);
    else
        printf("Employee number 222-555-2749 is NOT found in the record\n");

    printf("\n");
    //searchEmployeeBySalary
    //Example found
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 7.80);
    if (matchPtr != NULL)
        printf("Employee salary 7.80 is in record %d\n", matchPtr-EmployeeTable);
    else
        printf("Employee salary 7.80 is NOT found in the record\n");

    //Example not found
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 10.80);
    if (matchPtr != NULL)
        printf("Employee salary 10.80 is in record %d\n", matchPtr-EmployeeTable);
    else
        printf("Employee salary 10.80 is NOT found in the record\n");


    return EXIT_SUCCESS;
}
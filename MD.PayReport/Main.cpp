
#include <iostream>
#include <conio.h>

using namespace std;

struct Employee {
    int ID;
    string FirstName;
    string LastName;
    float HoursWorked;
    float HourlyRate;
};


Employee* GetEmployeeInfo(int index)
{
    Employee* pE = new Employee;

    cout << "Enter the ID for Employee " << index + 1 << ": ";
    cin >> pE->ID;

    cout << "Enter the First Name for Employee " << index + 1 << ": ";
    cin >> pE->FirstName;

    cout << "Enter the Last Name for Employee " << index + 1 << ": ";
    cin >> pE->LastName;

    cout << "Enter the Hours Worked for Employee " << index + 1 << ": ";
    cin >> pE->HoursWorked;

    cout << "Enter the Hourly Rate for Employee " << index + 1 << ": ";
    cin >> pE->HourlyRate;

    cout << "\n";
    return pE;
}


void PrintEmployeeReport(Employee* employees, int size)
{
    float TotalPay = 0;

    cout << "\nPay Report\n";
    cout << "-------------\n";

    for (int i = 0; i < size; i++)
    {
        float WeeklyPay = employees[i].HoursWorked * employees[i].HourlyRate;
        TotalPay += WeeklyPay;

        cout << employees[i].ID << ". " << employees[i].FirstName << ". " << employees[i].LastName << ". " << WeeklyPay << ".\n";
    }

    cout << "\nTotal Pay: $" << TotalPay << "\n";
}


int main()
{
    cout << "Enter the number of employees: ";
    int size = 0;
    cin >> size;
    cout << "\n";

    Employee *employees = new Employee[size];

    for (int i = 0; i < size; i++)
    {
        employees[i] = *GetEmployeeInfo(i);
    }

    PrintEmployeeReport(employees, size);

    
    delete[] employees;

    (void)_getch();
    return 0;
}

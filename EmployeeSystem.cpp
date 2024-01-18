#include <iostream>
#include <fstream>
#include <istream>

using namespace std;

int AskChoice()
{
    int choice;
    cout << "\n\n*************WELCOME TO EMPLOYEE MANAGEMENT SYSTEM**************\nWhat would you like to do?\n1.Display all Records.\n2.Add Record.\n3.Search Record. \n4.Exit System.\nEnter the respective number to proceed\n ";
    cin >> choice;
    return (choice);
}
void displayRecords()
{
    string myText;
    ifstream MyReadFile("EmployeeRecords.txt");
    cout << "\nEmpId\t\t\tNAME\t\tDESIGNATION\tSALARY(In Rs)\n";
    while (getline(MyReadFile, myText))
    {
        cout << myText << endl;
    }
    MyReadFile.close();
}
void AddRecord(string id, string name, string designation, int salary)
{
    ofstream fout;
    fout.open("EmployeeRecords.txt", ios::app);
    fout << id << "\t\t\t" << name << "\t\t" << designation << "\t\t" << salary << "\n";
    fout.close();
}
void SearchRecord(string id)
{
    string arr[4];
    cout << "\nFinding Record\n";
    string myText;
    ifstream MyReadFile("EmployeeRecords.txt");
    bool found = false;

    while (MyReadFile >> arr[0] >> arr[1] >> arr[2] >> arr[3])
    {
        if (arr[0] == id)
        {
            cout << "\nEmpId\t\t\tNAME\t\tDESIGNATION\tSALARY(In Rs)\n";
            cout << arr[0] << "\t\t\t" << arr[1] << "\t\t" << arr[2] << "\t\t" << arr[3] << endl
                 << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "\nSorry no such record was found\n";
    }
    MyReadFile.close();
}
int main()
{
    int choice = AskChoice();
    int employeeSalary;
    string employeeId, employeeName, employeeDesignation;

    while (choice != 4)
    {
        switch (choice)
        {
        case 1:
            cout << "\n\t\t\tDISPLAYING ALL EMPLOYEE INFORMATION\n\n";
            displayRecords();
            cout << endl;
            break;

        case 2:
            cout << "\nEnter the ID of the employee\n";
            cin >> employeeId;
            cout << "Enter the name of the employee\n";
            cin >> employeeName;
            cout << "Enter the designation of the employee\n";
            cin >> employeeDesignation;
            cout << "Enter the salary of the employee\n";
            cin >> employeeSalary;
            AddRecord(employeeId, employeeName, employeeDesignation, employeeSalary);
            cout << "\t\t\tAdded Record\n";
            break;
        case 3:
            cout << "\nEnter the employee ID you want to search\n";
            cin >> employeeId;
            SearchRecord(employeeId);
            break;
        default:
            cout << "\nInvalid choice. Try again.\n";
            break;
        }
        system("pause");
        choice = AskChoice();
    }
    cout << "\nExiting System....";
    return 0;
}
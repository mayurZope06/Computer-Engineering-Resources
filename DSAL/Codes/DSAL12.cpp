// Maintain an employee information system using an index sequential file, allowing users to add, delete, and display
// information. Handle cases where an employee's record does not exist.
// (Employee Data Management)
#include<iostream>
#include<iomanip>
using namespace std;

#define max 10
 
// Structure of Employee
struct employee {
    string name;
    long int employee_id;
    string designation;
    int salary;
};
 
int num = -1;
 
// Array of Employees to store the
// data in the form of the Structure
// of the Array
employee emp[max];

// Function to insert the data into
// given data type
void insert()
{
    if (num < max) {
        
        num++;
 
        cout << "Enter the information of the Employee\n";
 
        cout << "Employee ID: ";
        cin >> emp[num].employee_id;

        cout << "Name: ";
        cin >> emp[num].name;
 
        cout << "Designation: ";
        cin >> emp[num].designation;

        cout<<"Salary: ";
        cin>>emp[num].salary;

    }
    else {
        cout << "Employee Table Full\n";
    }

}
 
// Function to delete record at index i
void deleteIndex(int i)
{
    for (int j = i; j < num; j++) {
        emp[j].name = emp[j + 1].name;
        emp[j].employee_id = emp[j + 1].employee_id;
        emp[j].designation = emp[j + 1].designation;
        emp[j].salary = emp[j +1].salary;
    }
    return;
}

void displayAllRecords(){
    if(num == -1){
        cout<<"No records present!\n";
        return;
    }
    else{
        cout<<endl<<setw(5)<<"ID"<<setw(10)<<"NAME"<<setw(18)<<"DESIGNATION"<<setw(10)<<"SALARY\n";
        for(int i=0; i<num+1; i++){

            cout<<setw(5)<<emp[i].employee_id<<setw(10)<<emp[i].name<<setw(18)<<emp[i].designation<<setw(10)<<emp[i].salary<<endl;
            
        }
    }
}
 
// Function to delete record
void deleteRecord()
{
    int employee_id;

    cout << "Enter the Employee ID to Delete Record: ";
    cin >> employee_id;

    for (int i = 0; i < num+1; i++) {
        if (emp[i].employee_id == employee_id) {
            deleteIndex(i);
            num--;
            break;
        }
    }
    
}
 
void searchRecord()
{
    int employee_id;
    cout << "Enter the Employee ID to Search Record: ";
    cin >> employee_id;
 
    for (int i = 0; i < num+1; i++) {
 
        // If the data is found
        if (emp[i].employee_id == employee_id) {

            cout<<endl<<setw(5)<<"ID"<<setw(10)<<"NAME"<<setw(18)<<"DESIGNATION"<<setw(10)<<"SALARY\n";
            cout<<setw(5)<<emp[i].employee_id<<setw(10)<<emp[i].name<<setw(18)<<emp[i].designation<<setw(10)<<emp[i].salary<<endl;
            
            return;
        }
        
    }

    cout<<"Employee record not found.\n";

}
 
// Driver Code
int main()
{

    int option = 0;

    while(option != 5){
        cout << "\n----- Employee Management System -----\n";
        //cout << "Available Options:\n";
        cout << "1. Insert New Record\n";
        cout << "2. Display all Records\n";
        cout << "3. Delete Record\n";
        cout << "4. Search Record by Employee ID\n";
        cout << "5. Exit\n";
 
        cout<<"Enter your choice: ";
        cin >> option;

        switch(option){
            case 1:
                insert();
                break;

            case 2:
                displayAllRecords();
                break;

            case 3:
                deleteRecord();
                break;

            case 4:
                searchRecord();
                break;

            case 5:
                cout<<"\n***** You have exited *****\n";
                break;

            default:
                cout<<"Enter valid option!\n";
                break;
        }
    
    }
    return 0;
}

// OR 

// #include <iostream>
// #include <fstream>
// using namespace std;

// // Structure to represent an employee
// struct Employee {
//     int employeeId;
//     string name;
//     string designation;
//     double salary;
// };

// // Function to add an employee record to the file
// void addEmployee(const Employee& employee) {
//     ofstream file("employee_data.txt", ios::binary | ios::app);
//     if (!file) {
//         cout << "Error opening the file.\n";
//         return;
//     }

//     file.write(reinterpret_cast<const char*>(&employee), sizeof(Employee));
//     file.close();
// }

// // Function to delete an employee record from the file
// void deleteEmployee(int employeeId) {
//     ifstream inFile("employee_data.txt", ios::binary);
//     if (!inFile) {
//         cout << "Error opening the file.\n";
//         return;
//     }

//     ofstream outFile("temp.txt", ios::binary);
//     if (!outFile) {
//         cout << "Error opening the file.\n";
//         inFile.close();
//         return;
//     }

//     Employee employee;
//     bool found = false;

//     while (inFile.read(reinterpret_cast<char*>(&employee), sizeof(Employee))) {
//         if (employee.employeeId != employeeId)
//             outFile.write(reinterpret_cast<const char*>(&employee), sizeof(Employee));
//         else
//             found = true;
//     }

//     inFile.close();
//     outFile.close();

//     if (found) {
//         remove("employee_data.txt");
//         rename("temp.txt", "employee_data.txt");
//         cout << "Employee deleted successfully.\n";
//     } else {
//         remove("temp.txt");
//         cout << "Employee not found.\n";
//     }
// }

// // Function to display information of a particular employee
// void displayEmployee(int employeeId) {
//     ifstream file("employee_data.txt", ios::binary);
//     if (!file) {
//         cout << "Error opening the file.\n";
//         return;
//     }

//     Employee employee;
//     bool found = false;

//     while (file.read(reinterpret_cast<char*>(&employee), sizeof(Employee))) {
//         if (employee.employeeId == employeeId) {
//             cout << "Employee ID: " << employee.employeeId << endl;
//             cout << "Name: " << employee.name << endl;
//             cout << "Designation: " << employee.designation << endl;
//             cout << "Salary: " << employee.salary << endl;
//             found = true;
//             break;
//         }
//     }

//     file.close();

//     if (!found)
//         cout << "Employee not found.\n";
// }

// int main() {
//     int choice;
//     Employee employee;

//     do {
//         cout << "1. Add employee\n";
//         cout << "2. Delete employee\n";
//         cout << "3. Display employee information\n";
//         cout << "4. Quit\n";
//         cout << "Enter your choice: ";
//         cin >> choice;

//         switch (choice) {
//             case 1:
//                 cout << "Enter employee ID: ";
//                 cin >> employee.employeeId;
//                 cout << "Enter name: ";
//                 cin.ignore();
//                 getline(cin, employee.name);
//                 cout << "Enter designation: ";
//                 getline(cin, employee.designation);
//                 cout << "Enter salary: ";
//                 cin >> employee.salary;
//                 addEmployee(employee);
//                 break;
//             case 2:
//                 cout << "Enter employee ID to delete: ";
//                 cin >> employee.employeeId;
//                 deleteEmployee(employee.employeeId);
//                 break;
//             case 3:
//                 cout << "Enter employee ID to display: ";
//                 cin >> employee.employeeId;
//                 displayEmployee(employee.employeeId);
//                 break;
//                         case 4:
//                 cout << "Exiting the program.\n";
//                 break;
//             default:
//                 cout << "Invalid choice. Please try again.\n";
//         }
//     } while (choice != 4);

//     return 0;
// }
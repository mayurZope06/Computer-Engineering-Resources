// Maintain a student information system using a sequential file, allowing users to add, delete, and display
// information. Handle cases where a student's record does not exist.
// (Student Information System)
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class student {
    struct stud {
        int roll;
        char name[10];
        char div;
        char add[10];
    } rec;

public:
    void create();
    void display();
    int search();
    void Delete();
};

void student::create() {
    char ans;
    ofstream fout("stud.dat", ios::out | ios::binary);
    do {
        cout << "\n\tEnter Roll No of Student    : ";
        cin >> rec.roll;
        cout << "\n\tEnter a Name of Student     : ";
        cin >> rec.name;
        cout << "\n\tEnter a Division of Student : ";
        cin >> rec.div;
        cout << "\n\tEnter an Address of Student  : ";
        cin >> rec.add;
        fout.write((char*)&rec, sizeof(stud));
        cout << "\n\tDo You Want to Add More Records (y / n): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
    fout.close();
}

void student::display() {
    ifstream fin("stud.dat", ios::in | ios::binary);
    cout << "\n\tThe Content of File are:\n";
    cout << "\n\tRoll\tName\tDiv\tAddress";
    while (fin.read((char*)&rec, sizeof(stud))) {
        if (rec.roll != -1) {
            cout << "\n\t" << rec.roll << "\t" << rec.name << "\t" << rec.div << "\t" << rec.add;
        }
    }
    fin.close();
}

int student::search() {
    int r, i = 0;
    ifstream fin("stud.dat", ios::in | ios::binary);
    cout << "\n\tEnter a Roll No: ";
    cin >> r;
    while (fin.read((char*)&rec, sizeof(stud))) {
        if (rec.roll == r) {
            cout << "\n\tRecord Found...\n";
            cout << "\n\tRoll\tName\tDiv\tAddress";
            cout << "\n\t" << rec.roll << "\t" << rec.name << "\t" << rec.div << "\t" << rec.add;
            return i; // position found
        }
        i++;
    }
    fin.close();
    return -1; // record not found
}

void student::Delete() {
    int pos = search();
    if (pos == -1) {
        cout << "\n\tRecord Not Found";
        return;
    }

    fstream f("stud.dat", ios::in | ios::out | ios::binary);
    int offset = pos * sizeof(stud);
    f.seekp(offset);
    
    rec.roll = -1;
    strcpy(rec.name, "NULL");
    rec.div = 'N';
    strcpy(rec.add, "NULL");

    f.write((char*)&rec, sizeof(stud));
    f.close();
    cout << "\n\tRecord Deleted";
}

int main() {
    student obj;
    int ch, key;
    char ans;
    do {
        cout << "\n\t***** Student Information *****";
        cout << "\n\t1. Create\n\t2. Display\n\t3. Delete\n\t4. Search\n\t5. Exit";
        cout << "\n\t..... Enter Your Choice: ";
        cin >> ch;
        switch (ch) {
        case 1: obj.create();
            break;
        case 2: obj.display();
            break;
        case 3: obj.Delete();
            break;
        case 4:
            key = obj.search();
            if (key == -1)
                cout << "\n\tRecord Not Found...\n";
            break;
        case 5:
            break;
        default:
            cout << "\n\tInvalid Choice.";
        }
        cout << "\n\t..... Do You Want to Continue in Main Menu (y / n): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
    
    return 0;
}

// OR

// #include <iostream>
// #include <fstream>

// using namespace std;

// // Structure representing a record
// struct Record {
//     int id;
//     char name[50];
// };

// // Function to insert a record into the direct access file
// void insertRecord(fstream& file, const Record& record) {
//     file.seekp(record.id * sizeof(Record));
//     file.write(reinterpret_cast<const char*>(&record), sizeof(Record));
// }

// // Function to delete a record from the direct access file
// void deleteRecord(fstream& file, int id) {
//     Record record;
//     file.seekp(id * sizeof(Record));
//     file.write(reinterpret_cast<const char*>(&record), sizeof(Record));
// }

// // Function to display all records in the direct access file
// void displayRecords(fstream& file) {
//     file.seekg(0, ios::end);
//     int numRecords = file.tellg() / sizeof(Record);
//     file.seekg(0, ios::beg);

//     for (int i = 0; i < numRecords; ++i) {
//         Record record;
//         file.read(reinterpret_cast<char*>(&record), sizeof(Record));
//         if (record.id != 0) {
//             cout << "ID: " << record.id << ", Name: " << record.name << endl;
//         }
//     }
// }

// int main() {
//     fstream file("records.dat", ios::in | ios::out | ios::binary);

//     // Check if the file exists, if not create a new file
//     if (!file) {
//         file.open("records.dat", ios::out | ios::binary);
//         file.close();
//         file.open("records.dat", ios::in | ios::out | ios::binary);
//     }

//     int choice;
//     do {
//         cout << "1. Insert record" << endl;
//         cout << "2. Delete record" << endl;
//         cout << "3. Display records" << endl;
//         cout << "4. Exit" << endl;
//         cout << "Enter your choice: ";
//         cin >> choice;

//         switch (choice) {
//             case 1: {
//                 Record record;
//                 cout << "Enter ID: ";
//                 cin >> record.id;
//                 cout << "Enter Name: ";
//                 cin.ignore(); // Ignore the newline character from previous input
//                 cin.getline(record.name, 50);
//                 insertRecord(file, record);
//                 break;
//             }
//             case 2: {
//                 int id;
//                 cout << "Enter ID to delete: ";
//                 cin >> id;
//                 deleteRecord(file, id);
//                 break;
//             }
//             case 3: {
//                 displayRecords(file);
//                 break;
//             }
//             case 4: {
//                 cout << "Exiting..." << endl;
//                 break;
//             }
//             default:
//                 cout << "Invalid choice. Please try again." << endl;
//         }
//     } while (choice != 4);

//     file.close();

//     return 0;
// }
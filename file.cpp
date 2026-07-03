#include <iostream>
#include<conio.h>
#include<cstring>
#include<string>
using namespace std;
// Function declarations
void addStudent(int*& ids, string*& names, int*& att, int& count);
void markAttendance(int* att, string* names, int count);
void display(int* ids, string* names, int* att, int count);
void updateAttendance(int* ids, int* att, int count);
int main() {
 int* ids = nullptr;
 string* names = nullptr;
 int* attendance = nullptr;
 int studentCount = 0;
 int choice;
 do {
 cout << "\n--- Student Attendance System ---\n";
 cout << "1. Add Student\n";
 cout << "2. Mark Attendance\n";
 cout << "3. Display Attendance\n";
 cout << "4. Update Attendance\n";
 cout << "5. Exit\n";
 cout << "Enter choice: ";
 cin >> choice;
 if (choice == 1)
 addStudent(ids, names, attendance, studentCount);
 else if (choice == 2)
 markAttendance(attendance, names, studentCount);
 else if (choice == 3)
 display(ids, names, attendance, studentCount);
 else if (choice == 4)
 updateAttendance(ids, attendance, studentCount);
 else if (choice == 5)
 cout << "Program ended.\n";
 else
 cout << "Invalid choice!\n";
 } while (choice != 5);
 // delete the dynamic variables
 delete[] ids;
 delete[] names;
 delete[] attendance;
 _getch();
 return 0;
}
// Add students
void addStudent(int*& ids, string*& names, int*& att, int& count) {
 int* newIds = new int[count + 1];
 string* newNames = new string[count + 1];
 int* newAtt = new int[count + 1];
 for (int i = 0; i < count; i++) {
 newIds[i] = ids[i];
 newNames[i] = names[i];
 newAtt[i] = att[i];
 }
 cout << "Enter Student ID: ";
 cin >> newIds[count];
 cout << "Enter Student Name: ";
 cin.ignore();
 getline(cin, newNames[count]);
 newAtt[count] = 0;
 delete[] ids;
 delete[] names;
 delete[] att;
 ids = newIds;
 names = newNames;
 att = newAtt;
 count++;
 cout << "Student added successfully!\n";
}
// Mark attendance
void markAttendance(int* att, string* names, int count) {
 if (count == 0) {
 cout << "No students available.\n";
 return;
 }
 int present;
 for (int i = 0; i < count; i++) {
 cout << "Is " << names[i] << " present? (1=Yes, 0=No): ";
 cin >> present;
 if (present == 1)
 att[i]++;
 }
}

void display(int* ids, string* names, int* att, int count) {
 if (count == 0) {
 cout << "No data to display.\n";
 return;
 }
 cout << "\nID\tName\tAttendance\n";
 for (int i = 0; i < count; i++) {
 cout << ids[i] << "\t" << names[i] << "\t" << att[i] << endl;
 }
}

void updateAttendance(int* ids, int* att, int count) {
 int id;
 cout << "Enter student ID: ";
 cin >> id;
 for (int i = 0; i < count; i++) {
 if (ids[i] == id) {
 cout << "Enter new attendance: ";
 cin >> att[i];
 cout << "Attendance updated.\n";
 return;
 }
 }
 cout << "Student not found.\n";
}

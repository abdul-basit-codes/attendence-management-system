#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

class Student {
private:
    int id;
    string name;
    int attendance;

public:
    // Default constructor
    Student() : id(0), name(""), attendance(0) {}

    // Parameterized constructor
    Student(int id, string name, int attendance = 0)
        : id(id), name(name), attendance(attendance) {}

    // Getters
    int getId() const { return id; }
    string getName() const { return name; }
    int getAttendance() const { return attendance; }

    // Setters
    void setAttendance(int value) { attendance = value; }
    void incrementAttendance() { attendance++; }

    // Display this student's row
    void display() const {
        cout << id << "\t" << name << "\t" << attendance << endl;
    }
};

// ----------------------------
// Class: AttendanceSystem
// Manages a dynamic array of Student objects and all operations
// ----------------------------
class AttendanceSystem {
private:
    Student* students; // dynamic array of Student objects
    int count;          // number of students currently stored

public:
    // Constructor
    AttendanceSystem() : students(nullptr), count(0) {}

    // Destructor - cleans up dynamic memory automatically
    ~AttendanceSystem() {
        delete[] students;
    }

    void addStudent() {
        Student* newStudents = new Student[count + 1];

        // copy existing students into the new array
        for (int i = 0; i < count; i++) {
            newStudents[i] = students[i];
        }

        int newId;
        string newName;

        cout << "Enter Student ID: ";
        cin >> newId;
        cout << "Enter Student Name: ";
        cin.ignore();
        getline(cin, newName);

        newStudents[count] = Student(newId, newName, 0);

        delete[] students;
        students = newStudents;
        count++;

        cout << "Student added successfully!\n";
    }

    void markAttendance() {
        if (count == 0) {
            cout << "No students available.\n";
            return;
        }

        int present;
        for (int i = 0; i < count; i++) {
            cout << "Is " << students[i].getName() << " present? (1=Yes, 0=No): ";
            cin >> present;
            if (present == 1)
                students[i].incrementAttendance();
        }
    }

    void display() const {
        if (count == 0) {
            cout << "No data to display.\n";
            return;
        }

        cout << "\nID\tName\tAttendance\n";
        for (int i = 0; i < count; i++) {
            students[i].display();
        }
    }

    void updateAttendance() {
        int id;
        cout << "Enter student ID: ";
        cin >> id;

        for (int i = 0; i < count; i++) {
            if (students[i].getId() == id) {
                int newAttendance;
                cout << "Enter new attendance: ";
                cin >> newAttendance;
                students[i].setAttendance(newAttendance);
                cout << "Attendance updated.\n";
                return;
            }
        }
        cout << "Student not found.\n";
    }
};

// ----------------------------
// Main - drives the menu, delegates all work to AttendanceSystem object
// ----------------------------
int main() {
    AttendanceSystem system; // one object manages everything
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

        switch (choice) {
            case 1: system.addStudent(); break;
            case 2: system.markAttendance(); break;
            case 3: system.display(); break;
            case 4: system.updateAttendance(); break;
            case 5: cout << "Program ended.\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    _getch();
    return 0;
}

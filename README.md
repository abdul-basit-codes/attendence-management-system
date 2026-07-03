# attendence-management-system

# Student Attendance Management System

A simple console-based **Student Attendance Management System** built in C++ using dynamic memory allocation. This prototype was developed as a solution to the problem of inefficient, error-prone paper attendance registers used by university administrations.

## Problem Statement

Universities often rely on paper registers to track student attendance, which is slow and prone to mistakes. This program provides a lightweight computerized alternative that allows teachers to:

1. Add students (ID and name).
2. Mark attendance for multiple students in a single session.
3. Display current attendance records.
4. Update a specific student's attendance count.

## Features

- **Add Student** — Dynamically grows the internal arrays to register a new student with a unique ID and name.
- **Mark Attendance** — Iterates through all registered students and records whether each was present, incrementing their attendance count accordingly.
- **Display Attendance** — Prints a formatted table of all students' IDs, names, and attendance counts.
- **Update Attendance** — Looks up a student by ID and lets the teacher manually overwrite their attendance count.
- **Dynamic Memory Management** — Uses raw pointers and manual resizing (`new[]` / `delete[]`) instead of fixed-size arrays or STL containers, demonstrating core C++ memory management concepts.

## Tech Stack

- **Language:** C++
- **Libraries:** `<iostream>`, `<conio.h>`, `<cstring>`, `<string>`
- **Paradigm:** Procedural (function-based), dynamic arrays passed by reference/pointer

> **Note:** `<conio.h>` (used for `_getch()`) is a Windows/MSVC-specific header. On Linux or macOS, either remove the `_getch()` call or replace it with `std::cin.get()`.

## Project Structure

```
├── main()                  # Menu-driven control loop
├── addStudent()             # Adds a new student, resizing arrays
├── markAttendance()         # Records present/absent for each student
├── display()                 # Prints the attendance table
└── updateAttendance()       # Edits attendance for a given student ID
```

## How to Compile & Run

### Windows (MSVC / MinGW)
```bash
g++ attendance.cpp -o attendance.exe
attendance.exe
```

### Linux / macOS
Remove or replace `#include <conio.h>` and `_getch()` first, then:
```bash
g++ attendance.cpp -o attendance
./attendance
```

## Usage / Menu Options

```
--- Student Attendance System ---
1. Add Student
2. Mark Attendance
3. Display Attendance
4. Update Attendance
5. Exit
```

1. **Add Student** — Enter a numeric student ID and a full name (supports spaces via `getline`).
2. **Mark Attendance** — For each existing student, enter `1` for present or `0` for absent.
3. **Display Attendance** — View a table of `ID | Name | Attendance`.
4. **Update Attendance** — Enter a student's ID and a new attendance value to overwrite their count.
5. **Exit** — Frees all dynamically allocated memory and ends the program.

## Sample Output

```
ID      Name    Attendance
991     Ali     1
992     Hamza   1
```

## Known Limitations

- No persistent storage — all data is lost when the program exits (in-memory only).
- No input validation for duplicate student IDs or non-numeric input.
- Attendance is a raw counter (total days present) rather than a per-date record.
- `<conio.h>` limits portability to Windows without modification.

## Possible Future Improvements

- Add file-based (CSV) or database persistence so records survive restarts.
- Track attendance by date instead of a single running total.
- Validate duplicate IDs and sanitize numeric input.
- Replace raw pointer arrays with `std::vector` for safer memory management.
- Add a search/filter option in the display menu.

## Authors

- **Huzaifa Khan** — 01-134252-049
- **Abdul Basit** — 01-134252-002

BSCS 1C
Submitted to: Ma'am Saira Hameed

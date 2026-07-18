# Student Attendance Management System

A multi-implementation **Student Attendance Management System** — procedural C++, OOP C++, and a chalkboard-themed web frontend.

## Implementations

| File | Type | Description |
|------|------|-------------|
| `file.cpp` | Procedural C++ | Dynamic memory arrays, manual `new[]/delete[]` |
| `oop.cpp` | OOP C++ | `Student` and `AttendanceSystem` classes with encapsulation |
| `attendance-frontend.html` | Web App | Chalkboard-themed SPA with localStorage persistence |

## Features

- **Add Students** — Register with unique ID and name
- **Mark Attendance** — Record present/absent for each student
- **Display Records** — Formatted table with attendance counts
- **Update Attendance** — Edit attendance for a specific student
- **Web Frontend** — Beautiful chalkboard UI that works in any browser (no server needed)

## OOP Version (`oop.cpp`)

The OOP rewrite demonstrates:
- **Encapsulation** — Private member variables with public methods
- **Classes** — `Student` and `AttendanceSystem` as distinct abstractions
- **Separation of concerns** — Data model separate from system logic

## Web Frontend (`attendance-frontend.html`)

- Chalkboard-themed responsive design
- localStorage persistence (data survives page refresh)
- Add, mark, display, and delete operations
- Mobile-friendly

## Tech Stack

- **C++:** `<iostream>`, `<conio.h>`, `<cstring>`, `<string>`
- **Web:** HTML, CSS, vanilla JavaScript

## How to Compile & Run (C++)

### Windows
```bash
g++ file.cpp -o attendance.exe
attendance.exe
```

### Linux / macOS
Replace `#include <conio.h>` and `_getch()` with `std::cin.get()` first:
```bash
g++ file.cpp -o attendance
./attendance
```

### Web Frontend
Open `attendance-frontend.html` in any browser. No server required.

## Known Limitations

- C++ versions: No persistent storage (in-memory only)
- C++ versions: No duplicate ID validation
- `<conio.h>` is Windows-specific (needs replacement for Linux/macOS)

## Authors

- **Huzaifa Khan** — 01-134252-049
- **Abdul Basit** — 01-134252-002

BSCS 1C — Submitted to: Ma'am Saira Hameed

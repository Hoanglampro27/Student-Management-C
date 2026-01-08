# Student management system in C by Hoang Lam

## Introduction
This is a simple student management system written in C language.
The project helps user manage student information on the console, including name, ID, class and GPA.

## Main features
1. Add new students.
2. Display the list of students.
3. Update student information.
4. Delete the students.
5. Search students by ID.

## Technology used
- C language: structs, pointers, array,...
- Modular code structure (main.c, menu.c, student.c)

## Project structure
StudentManagement/
│
├── main.c          # Main function and program entry.
├── menu.c          # Handles menu functions.
├── menu.h          # Declarations of menu functions.
├── student.c       # Handles student information logic.
├── student.h       # Struct and function declarations for student.

## Future improvements
- Implement sorting student by GPA or name.
- Improve user interface.
- Add data storage to save student information into a file (e.g., data.txt) so data preserved after closing the program.
- Switch to linked list or C++/OOP.

## How to Compile and Run.
- Open the Terminal of Command prompt in project folder.
- Compile the C files using GCC: gcc main.c menu.c student.c -o student_management



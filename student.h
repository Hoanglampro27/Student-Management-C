#ifndef STUDENT_H //Tránh lỗi include cùng
#define STUDENT_H

#define Max 100

//Thiết kế dữ liệu cho sinh viên.
struct Student{ 
    char Studentname[50];
    int StudentID;
    char Studentclass[50];
    float GPA;
};

typedef struct Student st; //Chỗ có struct Student thì có thể thay bằng st

void addstudent(st stds[], int *count);
void displaystudent(st stds[], int count);
void searchIDstudent(st stds[], int count);
void deletestudent(st stds[], int *count);
void updatestudent(st stds[], int count);
void showMenu();
void savetofile(st stds[], int count);
int loadfromfile(st stds[]);

#endif
#include <stdio.h>
#include "menu.h"
#include "student.h"

int main(){

    struct Student stds[Max]; //Khai báo một mảng tên "students" có số phần tử là Max
                                  //Mỗi phần tử là một struct Students (struct Students chứa nhiều trường dữ liệu như tên, ID, lớp, GPA)
    int count=loadfromfile(stds); //Cho biết số sinh viên đã được đọc vào từ file

    int choice;
    do{
        showMenu();
        scanf("%d", &choice);
        switch(choice){
            case 1:
            addstudent(stds, &count);
            break;

            case 2:
            displaystudent(stds, count);
            break;

            case 3:
            updatestudent(stds, count);
            break;

            case 4:
            deletestudent(stds, &count);
            break;

            case 5:
            searchIDstudent(stds, count);
            break;

            case 0: //Sửa lại case 0 thành lưu dữ liệu vào file
            savetofile(stds, count);
            printf("Da luu du lieu cua sinh vien.\n");
            break;
            default:
            printf("Lua chon khong hop le.\n");
        }
    }
    while (choice !=0);
    return 0;
}

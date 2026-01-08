#include <stdio.h>
#include "menu.h"
#include "student.h"

int main(){
    int count=0;
    struct Student stds[Max]; //Khai báo một mảng tên "students" có số phần tử là Max
                                  //Mỗi phần tử là một struct Students (struct Students chứa nhiều trường dữ liệu như tên, ID, lớp, GPA)
    int choice;
    do{
        showMenu();
        scanf("%d", &choice);
        switch(choice){
            case 0: 
            printf("Da thoat!");
            break;

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
        }
    }
    while (choice!=0);
}

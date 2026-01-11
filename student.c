#include <stdio.h>
#include <string.h>
#include "student.h" //Chép toàn bộ nội dung của student.h vào trước khi compile
                     //Dùng "..." vì là file tự tạo, không phải thư viện chuẩn

//Hàm thêm sinh viên vào danh sách.
void addstudent(st stds[], int *count){
    if (*count>=Max){
        printf("Danh sach sinh vien da day.\n");
        return;
    }

    printf("Nhap ten sinh vien: ");
    scanf(" %[^\n]", &stds[*count].Studentname);

    printf("Nhap MSSV: ");
    scanf("%d", &stds[*count].StudentID);

    printf("Nhap lop: ");
    scanf(" %[^\n]", &stds[*count].Studentclass);

    printf("Nhap GPA: ");
    scanf("%f", &stds[*count].GPA);

    (*count)++; //bước này quan trọng

    printf("Nhap thong tin sinh vien thanh cong!\n");
    printf("\n");
}

//Hàm in ra danh sách sinh viên.
void displaystudent(st stds[], int count){
    if (count==0){
        printf("Danh sach khong co sinh vien nao");
        printf("\n");
        return;
    }
    
    printf("----Danh sach sinh vien----\n");
    for (int i=0;i<count;i++){ 
        printf("%s | %d | %s | %.2f\n", stds[i].Studentname, stds[i].StudentID, stds[i].Studentclass, stds[i].GPA);
    }
    printf("\n");
}

//Hàm giúp tìm kiếm sinh viên bằng ID.
void searchIDstudent(st stds[], int count){
    int ID2;
    int found=0;
    printf("Nhap MSSV can tim: ");
    scanf("%d", &ID2);

    for (int i=0;i<count;i++){
        if(ID2==stds[i].StudentID){
            printf("Sinh vien ban can tim: \n");
            printf("%s | %d | %s | %.2f\n", stds[i].Studentname, stds[i].StudentID, stds[i].Studentclass, stds[i].GPA);
            found=1;
        }
    }
    
    if (found==0) printf("Khong co sinh vien do trong danh sach.\n");
    printf("\n");
}

//Hàm xóa sinh viên.
void deletestudent(st stds[], int *count){
    int ID2;
    printf("Nhap ID sinh vien can xoa: ");
    scanf("%d", &ID2);

   for (int i=0;i<*count;i++){
    if (ID2==stds[i].StudentID){
        for (int j=i;j<*count-1;j++){
            stds[j]=stds[j+1];
        }
        (*count)--;
        printf("Xoa sinh vien do thanh cong.\n");
        printf("\n");
        return;
    }
   }
   printf("Khong tim thay sinh vien.\n");
   printf("\n");
}

//Hàm cập nhật thông tin của sinh viên.
void updatestudent(st stds[], int count){
    int ID2;
    printf("Nhap MSSV can cap nhat: ");
    scanf("%d", &ID2);

    for (int i=0;i<count;i++){
        if (ID2==stds[i].StudentID){
            printf("Nhap lai ten: ");
            scanf(" %[^\n]", stds[i].Studentname);

            printf("Nhap lai lop: ");
            scanf(" %[^\n]", stds[i].Studentclass);

            printf("Nhap lai GPA: ");
            scanf("%f", &stds[i].GPA);

            printf("Cap nhat thanh cong.\n");
            printf("\n");
            return;
        }
    }

    printf("Khong tim thay sinh vien.\n");
    printf("\n");
}

void savetofile(st stds[], int count){
    FILE *f; //Đặt con trỏ
    f=fopen("studentdata.txt", "w");
    if (f==NULL){
        printf("Loi tao hoac mo file. \n");
        exit(1);
    }
    for (int i=0;i<count;i++){
        fprintf(f, "%s %d %s %.2f\n", stds[i].Studentname, stds[i].StudentID, stds[i].Studentclass, stds[i].GPA);
    }
    fclose(f);
    printf("Da luu danh sach thanh cong.\n");
}

int loadfromfile(st stds[]){ //Hàm để đọc dữ liệu sinh viên vào mảng stds[]
    FILE *f;
    f=fopen("studentdata.txt","r");
    if (f=NULL){
        printf("Chua co file, khoi tao danh sach rong.\n");
        exit(1);
    }
    int count=0;
    while (fscanf(f,"%s %d %s %.2f\n",stds[count].Studentname, &stds[count].StudentID, stds[count].Studentclass, &stds[count].GPA)){
        count++;
        if(count >=Max) break; //Phòng trường hợp quá số lượng
    }

    fclose(f);

    printf("Da doc %d sinh vien tu file du lieu.\n", count);
    return count;
 
}
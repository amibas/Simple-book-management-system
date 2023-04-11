//
// Created by amiba on 2023/4/3.
//

#ifndef SIMPLE_BOOK_MANAGEMENT_SYSTEM_STUDENTPAGE_H
#define SIMPLE_BOOK_MANAGEMENT_SYSTEM_STUDENTPAGE_H


#include "DataManagement.h"
#include "conio.h"
#include <synchapi.h>
#include "NotClassified.h"


extern void Find_Book(void);    //查找书籍

extern Book *Find_BookofName(char *Book_num);   //通过书名查找书籍

extern void Change_Stupassword(Student *Stu_num);   //修改密码

extern void Find_Theborrow(Student *Stu_num);   //查找借阅

extern void Stu_Borrow(Student *Stu_num);   //学生借书

extern void Print_Book(void);   //打印书籍

extern Book *Book_exit(char *Book_num);  //判断书籍是否存在

extern int Ifborrow(Student *Stu_num, char *Book_num);  //判断是否借阅

extern void Stu_Back(Student *Stu_num);  //学生还书

extern void Print_Borbook(Student *Stu_num);    //打印借阅书籍

extern void Bake_Book(Student *Stu_num, char *Book_num);    //归还书籍


#endif //SIMPLE_BOOK_MANAGEMENT_SYSTEM_STUDENTPAGE_H

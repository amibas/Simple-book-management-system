//
// Created by amiba on 2023/4/3.
//

#ifndef SIMPLE_BOOK_MANAGEMENT_SYSTEM_STUDENTPAGE_H
#define SIMPLE_BOOK_MANAGEMENT_SYSTEM_STUDENTPAGE_H


#include "DataManagement.h"
#include "conio.h"
#include <synchapi.h>
#include "NotClassified.h"


extern void Find_Book(void);

extern Book *Find_BookofName(char *Book_num);

extern void Change_Stupassword(Student *Stu_num);

extern void Find_Theborrow(Student *Stu_num);

extern void Stu_Borrow(Student *Stu_num);

extern void Print_Book(void);

extern Book *Book_exit(char *Book_num);

extern int Ifborrow(Student *Stu_num, char *Book_num);

extern void Stu_Back(Student *Stu_num);

extern void Print_Borbook(Student *Stu_num);

extern void Bake_Book(Student *Stu_num, char *Book_num);


#endif //SIMPLE_BOOK_MANAGEMENT_SYSTEM_STUDENTPAGE_H

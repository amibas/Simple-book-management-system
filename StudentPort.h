//
// Created by amiba on 2023/4/3.
//

#ifndef SIMPLE_BOOK_MANAGEMENT_SYSTEM_STUDENTPORT_H
#define SIMPLE_BOOK_MANAGEMENT_SYSTEM_STUDENTPORT_H


#include <conio.h>
#include <synchapi.h>
#include "DataManagement.h"
#include "Gui.h"
#include "NotClassified.h"
#include "StudentPage.h"


extern void Student_Port(void);               //学生界面

extern void Student_Register(void);           //学生注册

extern void Find_Password(void);              //找回密码

extern Student *Find_Num(char *Stu_num);      //通过学号查找学生

extern void Student_Login(void);              //学生登录


#endif //SIMPLE_BOOK_MANAGEMENT_SYSTEM_STUDENTPORT_H

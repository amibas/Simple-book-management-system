//
// Created by amiba on 2023/4/2.
//

#ifndef SIMPLE_BOOK_MANAGEMENT_SYSTEM_GUI_H
#define SIMPLE_BOOK_MANAGEMENT_SYSTEM_GUI_H

#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include<windows.h>
#include "DataManagement.h"

extern void show_main(void);            //主界面

extern void show_stu(void);             //学生端

extern void show_stu_enter(void);       //学生页

extern void show_manager(void);         //管理端

extern void show_manager_enter(void);   //管理页

extern void showStudentNotice(void);    //学生公告页面

extern void showManagerNotice(void);    //管理员公告页面

#endif //SIMPLE_BOOK_MANAGEMENT_SYSTEM_GUI_H

//
// Created by amiba on 2023/4/3.
//

#ifndef SIMPLE_BOOK_MANAGEMENT_SYSTEM_MANAGEPAGE_H
#define SIMPLE_BOOK_MANAGEMENT_SYSTEM_MANAGEPAGE_H


#include "Gui.h"
#include "DataManagement.h"
#include "NotClassified.h"
#include "StudentPage.h"
#include "NoticePort.h"


extern void Manager_Port(void);                         //管理端

extern void Manager_Login(void);                        //管理端登录

extern Manager *Manager_check(char *Manager_num);       //管理端登录检查

extern void Manager_Look_Book(void);                    //管理端查看书籍

extern void Lookofnum(void);                            //编号升序查看书架

extern void Lookofrest(void);                           //剩余升序查看书架

extern void Lookofprice(void);                          //价格升序查看书架

extern void Manager_Print_Book(void);                   //管理端打印书籍

extern void Manager_Change_Password(Manager *Man_num);  //管理端修改密码

extern void Manager_Add_Book(void);                     //管理端添加书籍

extern void Manager_Add_Book1(void);                    //管理端添加书籍

extern void Manager_Add_Book2(void);                    //管理端添加书籍

extern void Manager_Down_Book(void);                    //管理端下架书籍

extern void Manager_Manager_Stu(void);                  //管理端管理学生

extern void Manager_Look_Stu(void);                     //管理端查看学生

extern void Manager_Return_Stu(void);                   //管理端还书

extern Student *Find_Stu(char *Stu_Stuty);              //管理端查找学生

extern void Manager_Del_Stu(void);                      //管理端删除学生


#endif //SIMPLE_BOOK_MANAGEMENT_SYSTEM_MANAGEPAGE_H

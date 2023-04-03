//
// Created by amiba on 2023/4/3.
//

#ifndef SIMPLE_BOOK_MANAGEMENT_SYSTEM_MANAGEPAGE_H
#define SIMPLE_BOOK_MANAGEMENT_SYSTEM_MANAGEPAGE_H


#include "Gui.h"
#include "DataManagement.h"
#include "NotClassified.h"
#include "StudentPage.h"


extern void Manager_Port(void);

extern void Manager_Login(void);

extern Manager *Manager_check(char *Manager_num);

extern void Manager_Look_Book(void);

extern void Lookofnum(void);

extern void Lookofrest(void);

extern void Lookofprice(void);

extern void Manager_Print_Book(void);

extern void Manager_Change_Password(Manager *Man_num);

extern void Manager_Add_Book(void);

extern void Manager_Add_Book1(void);

extern void Manager_Add_Book2(void);

extern void Manager_Down_Book(void);

extern void Manager_Manager_Stu(void);

extern void Manager_Look_Stu(void);

extern void Manager_Return_Stu(void);

extern Student *Find_Stu(char *Stu_Stuty);

extern void Manager_Del_Stu(void);


#endif //SIMPLE_BOOK_MANAGEMENT_SYSTEM_MANAGEPAGE_H

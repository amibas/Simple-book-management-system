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


extern void Student_Port(void);

extern void Student_Register(void);

extern void Find_Password(void);

extern Student *Find_Num(char *Stu_num);

extern void Student_Login(void);


#endif //SIMPLE_BOOK_MANAGEMENT_SYSTEM_STUDENTPORT_H

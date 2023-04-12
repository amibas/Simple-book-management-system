//
// Created by amiba on 2023/4/3.
//

#ifndef SIMPLE_BOOK_MANAGEMENT_SYSTEM_NOTCLASSIFIED_H
#define SIMPLE_BOOK_MANAGEMENT_SYSTEM_NOTCLASSIFIED_H


#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>


extern void RandStr(int l, char *ch);           //生成随机字符串

extern void Password_Input(char *Password);     //密码输入

extern int Password_Text(char *Password);       //密码判断

extern int Password_Text_Find(char *Password);  //密码判断（查找）


#endif //SIMPLE_BOOK_MANAGEMENT_SYSTEM_NOTCLASSIFIED_H

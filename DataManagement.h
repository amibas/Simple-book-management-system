//
// Created by amiba on 2023/4/2.
//

#ifndef SIMPLE_BOOK_MANAGEMENT_SYSTEM_DATAMANAGEMENT_H
#define SIMPLE_BOOK_MANAGEMENT_SYSTEM_DATAMANAGEMENT_H


#include "stdio.h"
#include "stdlib.h"
#include "string.h"


typedef struct book {
    char book_num[10];                //书号
    char book_name[20];                //书名
    char book_at_name[30];            //作者名
    char book_cp_name[30];            //出版社
    float book_price;                //价格
    int book_rest;                    //库存
    struct book *next;                //下本书
} Book;

typedef struct stu {
    char stu_acc[10];                //学生账号
    char stu_passw[15];                //学生密码
    char stu_find_question[30];        //密保问题
    char stu_find_passw[15];        //密保问题密码
    char stu_num[10];                //学生学号
    char stu_name[20];                //学生姓名
    char stu_tel[15];                //学生电话
    char stu_bor_book[10][20];        //所借书号
    struct stu *next;                //下位学生
} Student;

typedef struct manager {
    char man_name[15];                //管理员姓名
    char man_acc[10];                //管理员账号
    char man_passw[15];                //管理员密码
    struct manager *next;            //下个管理员
} Manager;

//公告结构体链表
typedef struct notice {
    char title[20];                    //公告标题
    char notice[100];                //公告内容
    struct notice *next;            //下个公告
} Notice;

extern Book *Book_head;
extern Student *Student_head;
extern Manager *Manager_head;


extern Book *Book_load();

extern Student *Student_load(void);

extern Manager *Manager_load(void);

extern void Save_Book(void);

extern void Save_Student(void);

extern void Save_Manger(void);

extern void Massage_Save(void);

#endif //SIMPLE_BOOK_MANAGEMENT_SYSTEM_DATAMANAGEMENT_H

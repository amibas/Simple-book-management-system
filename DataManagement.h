//
// Created by amiba on 2023/4/2.
//

#ifndef SIMPLE_BOOK_MANAGEMENT_SYSTEM_DATAMANAGEMENT_H
#define SIMPLE_BOOK_MANAGEMENT_SYSTEM_DATAMANAGEMENT_H


#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"


typedef struct book {             //书籍结构体链表
    char book_num[10];                //书号
    char book_name[20];                //书名
    char book_at_name[30];            //作者名
    char book_cp_name[30];            //出版社
    float book_price;                //价格
    int book_rest;                    //库存
    struct book *next;                //下本书
} Book;

typedef struct stu {            //学生结构体链表
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

typedef struct manager {    //管理员结构体链表
    char man_name[15];                //管理员姓名
    char man_acc[10];                //管理员账号
    char man_passw[15];                //管理员密码
    struct manager *next;            //下个管理员
} Manager;

//公告结构体链表
typedef struct notice {             //公告结构体链表
    char notice_num[10];            //公告编号
    char date[20];                  //公告日期
    char title[20];                 //公告标题
    char notice[100];               //公告内容
    struct notice *next;            //下个公告
} Notice;

extern Book *Book_head;         //书籍头指针
extern Student *Student_head;   //学生头指针
extern Manager *Manager_head;   //管理员头指针
extern Notice *Notice_head;     //公告头指针

extern Book *Book_load();   //加载书籍

extern Student *Student_load(void); //加载学生

extern Manager *Manager_load(void); //加载管理员

extern Notice *Notice_load(void);   //加载公告

extern void Save_Book(void);    //保存书籍

extern void Save_Student(void); //保存学生

extern void Save_Manger(void);  //保存管理员

extern void Save_Notice(void);  //保存公告

extern void Massage_Save(void); //保存所有信息

#endif //SIMPLE_BOOK_MANAGEMENT_SYSTEM_DATAMANAGEMENT_H

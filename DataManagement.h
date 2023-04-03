//
// Created by amiba on 2023/4/2.
//

#ifndef SIMPLE_BOOK_MANAGEMENT_SYSTEM_DATAMANAGEMENT_H
#define SIMPLE_BOOK_MANAGEMENT_SYSTEM_DATAMANAGEMENT_H


#define USER_FILE "user.txt"
#define BOOK_FILE "book.txt"
#define NOTICE_FILE "notice.txt"

#include "FileTools.h"
#include "stdlib.h"

typedef struct bookInfo {
    int bookId;             //编号
    char bookName[20];      //书名
    char author[10];        //作者
    int total;              //数量
    struct bookInfo *next;  //链表链接
} BOOK;

typedef struct userInfo {
    int userId;             //用户ID
    char userName[10];      //用户名
    char userPassword[16];  //用户密码
    char sex;               //性别
    int level;              //权限等级
    BOOK *bookHead;         //借阅的书籍
    struct userInfo *next;  //链表链接
} USER;

typedef struct notice {
    int noticeId;           //公告ID
    char noticeTitle[20];   //公告标题
    char text[400];         //正文
    char noticeTime[11];    //发布时间
    struct notice *next;    //链表链接
} NOTICE;


extern int addUser(USER *user);
extern int findUser(char *userName);    //查找用户
extern int userPasswordCheck(char *userName, char *userPassword);    //密码检查
#endif //SIMPLE_BOOK_MANAGEMENT_SYSTEM_DATAMANAGEMENT_H

//
// Created by amiba on 2023/4/2.
//

#include "Gui.h"


void show_main(void) {
    system("cls");
    printf("\t\t\t\t**********************************************\n");
    printf("\t\t\t\t*             欢迎使用图书管理系统           *\n");
    printf("\t\t\t\t**********************************************\n");
    printf("\n");
    printf("\t\t\t\t\t*******************************\n");
    printf("\t\t\t\t\t   _____ ____  __  __  _____ \n"
           "\t\t\t\t\t  / ____|  _ \\|  \\/  |/ ____|\n"
           "\t\t\t\t\t | (___ | |_) | \\  / | (___  \n"
           "\t\t\t\t\t  \\___ \\|  _ <| |\\/| |\\___ \\ \n"
           "\t\t\t\t\t  ____) | |_) | |  | |____) |\n"
           "\t\t\t\t\t |_____/|____/|_|  |_|_____/ \n"
           "\t\t\t\t\t                            \n");
    printf("\t\t\t\t\t*******************************\n");
    printf("\n\t\t\t\t\t   *************************\n\n");
    printf("\t\t\t\t\t\t   1)学生端\n");
    printf("\t\t\t\t\t\t   2)管理员端\n");
    printf("\t\t\t\t\t\t   0)退出\n");
    printf("\n\t\t\t\t\t   *************************\n\n");
}

void show_stu(void) {
    system("CLS");
    printf("\n\n\n\t\t\t\t\t*************************");
    printf("\n\t\t\t\t\t*\t 学生端 \t*");
    printf("\n\t\t\t\t\t*************************\n\n");
    printf("\t\t\t\t\t\t1)登录\n");
    printf("\t\t\t\t\t\t2)注册\n");
    printf("\t\t\t\t\t\t3)找回密码\n");
    printf("\t\t\t\t\t\t0)返回\n");
    printf("\n\t\t\t\t\t*************************\n\n");
}

void show_stu_enter(void) {
    system("CLS");
    printf("\n\n\n\t\t\t\t\t*************************");
    printf("\n\t\t\t\t\t*\t 学生页 \t*");
    printf("\n\t\t\t\t\t*************************\n\n");
    printf("\t\t\t\t\t\t1)借书\n");
    printf("\t\t\t\t\t\t2)还书\n");
    printf("\t\t\t\t\t\t3)查书\n");
    printf("\t\t\t\t\t\t4)浏览借阅情况\n");
    printf("\t\t\t\t\t\t5)查看公告\n");
    printf("\t\t\t\t\t\t6)修改密码\n");
    printf("\t\t\t\t\t\t0)返回\n");
    printf("\n\t\t\t\t\t*************************\n\n");
}

void show_manager(void) {
    system("CLS");
    printf("\n\n\n\t\t\t\t\t*************************");
    printf("\n\t\t\t\t\t\t 管理员端");
    printf("\n\t\t\t\t\t*************************\n\n");
    printf("\t\t\t\t\t\t1)登录\n");
    printf("\t\t\t\t\t\t0)返回\n");
    printf("\n\t\t\t\t\t*************************\n\n");
}

void show_manager_enter(void) {
    system("CLS");
    printf("\n\n\n\t\t\t\t\t*************************");
    printf("\n\t\t\t\t\t\t 管理员页");
    printf("\n\t\t\t\t\t*************************\n\n");
    printf("\t\t\t\t\t\t1)上架书籍\n");
    printf("\t\t\t\t\t\t2)下架书籍\n");
    printf("\t\t\t\t\t\t3)浏览书架\n");
    printf("\t\t\t\t\t\t4)管理学生账号\n");
    printf("\t\t\t\t\t\t5)修改密码\n");
    printf("\t\t\t\t\t\t6)进入公告界面\n");
    printf("\t\t\t\t\t\t0)退出\n");
    printf("\n\t\t\t\t\t*************************\n\n");
}

//显示学生公告界面
void showStudentNotice(void) {
    system("CLS");
    printf("\n\n\n\t\t\t\t\t\t 公告");
    //当前图书馆书籍总量，与借书最多的人
    printf("\n\t\t\t\t\t*************************\n");
    printf("\t\t\t\t\t当前图书馆书籍总量：%d本", getBookCount());
    printf("\n\t\t\t\t\t*************************\n\n");
    printf("\t\t\t\t\t\t 1)查看公告\n");
    printf("\t\t\t\t\t\t 2)搜索公告\n");
    printf("\t\t\t\t\t\t 0)返回\n");
    printf("\n\t\t\t\t\t*************************\n\n");
}

/*管理员公告界面*/
void showManagerNotice(void) {
    system("CLS");
    printf("\n\n\n\t\t\t\t 公告");
    //当前图书馆书籍总量，与借书最多的人
    printf("\n\t\t\t*************************\n");
    printf("\t\t\t当前图书馆书籍总量：%d本", getBookCount());
    printf("\n\t\t\t*************************\n\n");
    printf("\t\t\t\t1)查看公告\n");
    printf("\t\t\t\t2)发布公告\n");
    printf("\t\t\t\t3)删除公告\n");
    printf("\t\t\t\t4)搜索公告\n");
    printf("\t\t\t\t0)返回\n");
    printf("\n\t\t\t*************************\n\n");
}
//
// Created by amiba on 2023/4/3.
//

#include "StudentPort.h"


/**
 * 学生端
 */
void Student_Port(void) {
    char sp = '1';  //学生端选择

    //学生端界面
    while (sp != '0') {
        show_stu(); //显示学生端界面
        printf("\t\t\t：");

        scanf("%c", &sp);   //输入选择
        //判断选择
        switch (sp) {
            case '1':
                Student_Login();    //学生登录
                break;
            case '2':
                Student_Register(); //学生注册
                break;
            case '3':
                Find_Password();    //找回密码
                break;
            case '0':
                break;  //退出
            default:    //输入错误
                printf("\t\t输入错误，请重新输入：\n");
                Sleep(1500);
                break;
        }
        while (getchar() != '\n');  //清空缓冲区
    }
}

/**
 * 学生注册
 */
void Student_Register(void) {
    //初始化变量
    Student *t; //临时指针
    Student *new = (Student *) malloc(sizeof(Student)); //新节点
    new->next = NULL;   //新节点指针域置空

    //初始化新节点
    for (int i = 0; i < 10; i++) {
        new->stu_bor_book[i][0] = '0';
        new->stu_bor_book[i][1] = '\0';
    }

    //注册界面
    printf("\n\t\t欢迎来到注册系统！\n");
    Sleep(500);
    printf("\t\t正在加载···\n");
    Sleep(500);
    printf("\t\t请输入以下信息\n");
    printf("\t\t学号：");
    scanf("%s", new->stu_num);
    printf("\t\t姓名：");
    scanf("%s", new->stu_name);
    printf("\t\t电话：");
    scanf("%s", new->stu_tel);
    printf("\t\t密码：");
    Password_Input(new->stu_passw);
    printf("\n\t\t再次输入密码：");
    //判断密码是否正确
    if (Password_Text(new->stu_passw) == 0) {
        printf("\n\t\t您已连续输错3次，将退出注册系统···");
        Sleep(5000);
        free(new);
        return;
    }

    //密保问题
    printf("\n\n\t\t密保问题用于找回密码\n");
    printf("\t\t如：\n");
    printf("\t\t    我母亲的生日是？\n");
    printf("\t\t    我父亲的生日是？\n");
    printf("\t\t    我的生日是？\n");
    printf("\n\t\t密保问题：");
    scanf("%s", new->stu_find_question);
    printf("\t\t密保问题密码：");
    Password_Input(new->stu_find_passw);
    printf("\n\t\t再次输入密保问题密码：");
    if (Password_Text(new->stu_find_passw) == 0) {
        printf("\n\t\t您已连续输错3次，将退出注册系统···");
        Sleep(5000);
        free(new);
        return;
    }

    //注册成功
    Sleep(500);
    printf("\n\t\t正在注册···\n");
    Sleep(1000);
    printf("\t\t···\n");
    Sleep(1000);
    printf("\t\t···\n");
    Sleep(1000);
    printf("\t\t注册成功！\n");
    RandStr(6, new->stu_acc);
    printf("\t\t您的账号是: %s\n", new->stu_acc);
    printf("\t\t请务必牢记账号密码！\n");
    while (getchar() != '\n');
    t = Student_head;   //临时指针指向头节点
    while (t->next) {   //遍历链表
        t = t->next;
    }
    t->next = new;      //将新节点插入链表

    //按任意键退出
    printf("\t\t按任意键退出");
    getch();
}

/*找回密码*/
void Find_Password(void) {
    Student *find_tem;
    char num_tem[50];
    printf("\t\t欢迎来到找回密码系统\n");
    Sleep(500);
    printf("\t\t···\n");
    Sleep(500);
    int l = 1;
    while (l != 6) {
        printf("\t\t请输入六位账号：");
        gets(num_tem);
        l = strlen(num_tem);
        if (l != 6)
            printf("\t\t账号有误，请输入正确长度的账号\n");
    }
    num_tem[6] = '\0';
    find_tem = Find_Num(num_tem);
    printf("\t\t您输入的账号：");
    puts(num_tem);
    Sleep(500);
    printf("\t\t正在为您查找\n");
    Sleep(500);
    printf("\t\t···\n");
    Sleep(500);
    if (find_tem == NULL) {
        printf("\t\t抱歉，无此账号，即将退出注册系统\n");
        Sleep(1000);
        printf("\t\t···\n");
        Sleep(1500);
        return;
    }
    printf("\t\t%s，您好！\n", find_tem->stu_name);
    Sleep(300);
    printf("\t\t你设置的密保问题是： %s\n", find_tem->stu_find_question);
    Sleep(300);
    printf("\t\t请输入你的密保问题密码：");
    if (Password_Text_Find(find_tem->stu_find_passw) == 0) {
        printf("\n\t\t您已连续输错3次，将退出找回密码系统···\n");
        Sleep(1500);
        return;
    }
    Sleep(500);
    printf("\n\t\t正在查找\n");
    Sleep(500);
    printf("\t\t···\n");
    Sleep(500);
    printf("\t\t···\n");
    Sleep(500);
    printf("\t\t%s 您好，您的密码是 ：%s", find_tem->stu_name, find_tem->stu_passw);
    printf("\n\t\t请牢记您的密码\n");
    printf("\t\t按任意键退出");
    getch();


}

Student *Find_Num(char *Stu_num) {
    Student *t = Student_head->next;
    while (t) {
        if (strcmp(t->stu_acc, Stu_num) == 0)
            break;
        t = t->next;
    }
    return t;
}

/*学生端登录*/
void Student_Login(void) {

    char sl = '1';
    char enter_num[50];
    int l = 1;

    Student *enter_stu;
    while (getchar() != '\n');  //清空缓冲区
    while (l != 6) {
        printf("\n\t\t请输入你的账号：");
        gets(enter_num);
        l = strlen(enter_num);
        if (l != 6)
            printf("\t\t账号有误，请输入正确长度的账号\n");
    }
    enter_num[6] = '\0';
    enter_stu = Find_Num(enter_num);
    if (enter_stu == NULL) {
        printf("\n\t\t抱歉，无此账号");
        Sleep(500);
        printf("\n\t\t按任意键退出");
        getch();
        return;
    }
    printf("\t\t请输入密码：");
    if (Password_Text_Find(enter_stu->stu_passw) == 0) {
        printf("\n\t\t您已连续输错3次，将退出登录系统···");
        Sleep(2000);
        return;
    }
    Sleep(500);
    printf("\n\t\t正在登录");
    Sleep(500);
    printf("\n\t\t···\n");
    Sleep(500);
    printf("\n\t\t登录成功！\n");
    Sleep(1000);


    while (sl != '0') {
        show_stu_enter();
        printf("\t\t：");
        scanf("%c", &sl);
        while (getchar() != '\n');  //清空缓冲区
        switch (sl) {
            case '1':
                Stu_Borrow(enter_stu);              //借书
                break;
            case '2':
                Stu_Back(enter_stu);                //还书
                break;
            case '3':
                Find_Book();                                //查找书籍
                break;
            case '4':
                Find_Theborrow(enter_stu);          //查找借阅
                break;
            case '5':
                studentNotice();                            //查看公告
                break;
            case '6':
                Change_Stupassword(enter_stu);
                break;
            case '0':
                break;
            default:
                printf("\t\t输入错误，请重新输入\n");
                Sleep(1500);
                break;
        }
    }
}
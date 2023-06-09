//
// Created by amiba on 2023/4/10.
//


#include "NoticePort.h"
#include "NotClassified.h"


/**
 * 学生公告页面
 */
void studentNotice() {
    char choice = '1';

    while (choice != '0') {
        showStudentNotice();
        printf("\t\t\t\t：");
        scanf("%c", &choice);
        switch (choice) {
            case '1':
                View_Notice();  //查看公告
                break;
            case '2':
                findNotice();   //查找公告
                break;
            case '0':
                break;          //退出
            default:
                printf("\t\t输入错误，请重新输入：");
                Sleep(1500);
                break;
        }
        //清空缓冲区
        while (getchar() != '\n');
    }
}

/**
 * 管理员公告页面
 */
void manageNotice() {
    char choice = '1';

    while (choice != '0') {
        showManagerNotice();
        printf("\t\t请输入选择：");
        choice = getchar();
        while (getchar() != '\n');  //清空缓冲区
        switch (choice) {
            case '1':
                View_Notice();      //查看公告
                break;
            case '2':
                Publish_Notice();   //发布公告
                break;
            case '3':
                Delete_Notice();    //删除公告
                break;
            case '4':
                findNotice();       //查找公告
                break;
            case '0':
                break;              //退出
            default:
                printf("\t\t输入错误，请重新输入：");
                Sleep(1500);
                break;
        }
        //清空缓冲区
        while (getchar() != '\n');
    }
}

/**
 * 显示当前所有公告的编号、标题和发布时间
 */
void View_Notice() {
    //公告头
    Notice *p = Notice_head;
    //打印公告信息
    printf("\t\t公告编号\t\t公告标题\t\t发布时间\n");
    while (p->next != NULL) {
        p = p->next;
        printf("\t\t%s\t\t%s\t\t%s\n", p->notice_num, p->title, p->date);
    }
    //输入编号查看具体内容,输入0返回
    printf("\t\t请输入你要查看的公告编号(输入0返回)：");
    char num[10];
    scanf("%s", num);
    if (strcmp(num, "0") == 0) {
        return;
    }
    //查找公告
    p = Notice_head;
    while (p->next != NULL) {
        p = p->next;
        if (strcmp(p->notice_num, num) == 0) {
            printf("\t\t公告编号：%s\n", p->notice_num);
            printf("\t\t公告标题：%s\n", p->title);
            printf("\t\t公告内容：%s\n", p->notice);
            printf("\t\t发布时间：%s\n", p->date);
            printf("\t\t任意键返回");
            _getch();
            return;
        }
    }
    if (p->next == NULL) {
        printf("\t\t没有找到该公告\n");
    }
    //任意键返回
    printf("\t\t任意键返回");
    _getch();
}

/**
 * 发布公告
 */
void Publish_Notice() {
    //公告头
    Notice *p = Notice_head;
    //移动到链表尾
    while (p->next != NULL) {
        p = p->next;
    }
    //创建新节点
    Notice *new = (Notice *) malloc(sizeof(Notice));
    new->next = NULL;
    //输入公告信息
    printf("\t\t请输入公告标题：");
    strcmp(new->title, "\0");
    scanf("%s", new->title);
    printf("\t\t请输入公告内容：");
    strcmp(new->notice, "\0");
    scanf("%s", new->notice);
    //生成公告编号
    strcmp(new->notice_num, "\0");
    RandStr(8, new->notice_num);
    //生成发布时间
    time_t tt = time(0);
    //产生“YYYY-MM-DD-hh:mm:ss”格式的字符串。
    char s[32];
    strftime(s, sizeof(s), "%Y-%m-%d-%H:%M:%S", localtime(&tt));
    //s[i] = '\n';
    s[31] = '\n';
    strcpy(new->date, s);
    //将新节点插入链表
    p->next = new;
    //将公告信息写入文件
    Save_Notice();
    printf("\t\t发布成功\n");
    Sleep(1500);
}

/*删除公告*/
void Delete_Notice() {
    //公告头
    Notice *p = Notice_head;
    //打印公告信息
    printf("\t\t公告编号\t\t公告标题\t\t发布时间\n");
    while (p->next != NULL) {
        p = p->next;
        printf("\t\t%s\t\t%s\t\t%s\n", p->notice_num, p->title, p->date);
    }
    //输入编号查看具体内容,输入0返回
    printf("\t\t请输入你要删除的公告编号(输入0返回)：");
    char num[10];
    scanf("%s", num);
    if (strcmp(num, "0") == 0) {
        return;
    }
    //查找公告
    p = Notice_head;
    while (p->next != NULL) {
        if (strcmp(p->next->notice_num, num) == 0) {
            Notice *q = p->next;    //q指向要删除的节点
            p->next = q->next;      //删除节点
            free(q);
            printf("\t\t删除成功\n");
            Sleep(1500);
            return;
        }
        p = p->next;
    }
    if (p->next == NULL) {
        printf("\t\t没有找到该公告\n");
    }
    //任意键返回
    printf("\t\t任意键返回");
    _getch();
}

/*搜索公告*/
void findNotice() {
    //公告头
    Notice *p = Notice_head;
    //打印公告信息
    printf("\t\t公告编号\t\t公告标题\t\t发布时间\n");
    while (p->next != NULL) {
        p = p->next;
        printf("\t\t%s\t\t%s\t\t%s\n", p->notice_num, p->title, p->date);
    }
    //输入编号查看具体内容,输入0返回
    printf("\t\t请输入你要查找的公告标题(输入0返回)：");
    char title[20];
    scanf("%s", title);
    if (strcmp(title, "0") == 0) {
        return;
    }
    //模糊搜索公告
    p = Notice_head;
    while (p->next != NULL) {
        p = p->next;
        int n = 0;
        for (int i = 0; i < strlen(title); i++) {
            for (int j = 0; j < strlen(p->title); j++) {
                if (title[i] == p->title[j]) {
                    n = 1;
                    break;
                } else {
                    n = 0;
                }

            }
            if (i == strlen(title) - 1 && n == 1) {
                printf("\t\t公告编号：%s\n", p->notice_num);
                printf("\t\t公告标题：%s\n", p->title);
                printf("\t\t公告内容：%s\n", p->notice);
                printf("\t\t发布时间：%s\n", p->date);
                printf("\t\t任意键返回");
                _getch();
                return;
            }
        }
    }
    if (p->next == NULL) {
        printf("\t\t没有找到该公告\n");
    }
    //任意键返回
    printf("\t\t任意键返回");
    _getch();
}
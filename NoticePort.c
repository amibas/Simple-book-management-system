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
        printf("\t\t：");
        choice = getchar();
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
    }
}

/**
 * 显示当前所有公告的编号、标题和发布时间
 */
void View_Notice() {
    //打开公告文件
    FILE *fp;
    fp = fopen("Notice.txt", "r");
    if (fp == NULL) {
        printf("\t\t打开失败\n");
        exit(1);
    }
    //读取公告信息
    Notice *p = Notice_load();
    Notice *q = p;
    //显示公告信息
    printf("\t\t公告编号\t\t公告标题\t\t发布时间\n");
    while (q != NULL) {
        printf("\t\t%s\t\t%s\t\t%s\n", q->notice_num, q->title, q->date);
        q = q->next;
    }
    //无公告提示
    if (p == NULL) {
        printf("\t\t暂无公告\n");
    }


    fclose(fp);
    Sleep(1500);
    //任意键返回
    printf("\t\t任意键返回");
    _getch();
}

/**
 * 发布公告
 */
void Publish_Notice() {
    //打开公告文件
    Notice *p = (Notice *) malloc(sizeof(Notice));
    FILE *fp;
    fp = fopen("Notice.txt", "a");
    if (fp == NULL) {
        printf("\t\t打开失败\n");
        exit(1);
    }

    //用随机字符自动生成公告编号
    RandStr(9, p->notice_num);

    //标题
    printf("\t\t请输入公告标题：");
    scanf("%s", p->title);

    //自动生成公告发布时间
    time_t t;
    time(&t);
    strcpy(p->notice_num, ctime(&t));

    //内容
    printf("\t\t请输入公告内容：");
    scanf("%s", p->notice);

    //将公告信息写入文件
    Save_Notice();
    fclose(fp);
}

/*删除公告*/
void Delete_Notice() {
    //将公告文件清空
    FILE *fp;
    fp = fopen("Notice.txt", "w");
    if (fp == NULL) {
        printf("\t\t打开失败\n");
        exit(1);
    }
    fclose(fp);
    printf("\t\t删除成功\n");
    Sleep(1500);
}

/*搜索公告*/
void findNotice() {
    //输入搜索的公告标题
    char title[20];
    printf("\t\t请输入公告标题：");
    scanf("%s", title);
    //打开公告文件
    FILE *fp;
    fp = fopen("Notice.txt", "r");
    if (fp == NULL) {
        printf("\t\t打开失败\n");
        exit(1);
    }
    //查找公告
    while (!feof(fp)) {
        char notice[100];
        fscanf(fp, "%s", notice);
        if (strcmp(notice, title) == 0) {
            printf("\t\t%s\n", notice);
            Sleep(1500);
            return;
        }
    }
    printf("\t\t未找到该公告\n");
    Sleep(1500);
}
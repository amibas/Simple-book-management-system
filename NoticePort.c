//
// Created by amiba on 2023/4/10.
//


#include "NoticePort.h"


/*公告端口*/
void Notice_Port() {
    char sp = '1';
    printf("\t\t\t：");

    scanf("%c", &sp);
    while (getchar() != '\n');
    switch (sp) {
        case '1':
            //查看公告
            View_Notice();
            break;
        case '2':
            //发布公告
            Publish_Notice();
            break;
        case '3':
            //删除公告
            Delete_Notice();
            break;
        case '0':
            break;
        default:
            printf("\t\t输入错误，请重新输入：\n");
            Sleep(1500);
            break;
    }
}

/*查看公告*/
void View_Notice() {
    //从文件中读取公告信息
    FILE *fp;
    fp = fopen("Notice.txt", "r");
    if (fp == NULL) {
        printf("\t\t打开失败\n");
        exit(1);
    }
    getc(fp);
    if (feof(fp)) {
        fclose(fp);
        printf("\t\t暂无公告\n");
        Sleep(1500);
        return;
    }
    rewind(fp);
    printf("\t\t公告如下：\n");
    while (!feof(fp)) {
        char notice[100];
        fscanf(fp, "%s", notice);
        printf("\t\t%s\n", notice);
    }
}

/*发布公告*/
void Publish_Notice() {
    //将公告信息写入文件
    FILE *fp;
    fp = fopen("Notice.txt", "a");
    if (fp == NULL) {
        printf("\t\t打开失败\n");
        exit(1);
    }
    printf("\t\t请输入公告内容：");
    char notice[100];
    scanf("%s", notice);
    fprintf(fp, "%s\n", notice);
    fclose(fp);
    printf("\t\t发布成功\n");
    Sleep(1500);
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
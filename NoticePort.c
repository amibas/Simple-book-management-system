//
// Created by amiba on 2023/4/10.
//


#include "NoticePort.h"

/*查看公告*/
void View_Notice() {
    //从文件中读取公告信息
    FILE *fp;
    fp = fopen("Notice.txt", "r");
    //如果不存在公告文件，就新建一个
    if (fp == NULL) {
        fp = fopen("Notice.txt", "w");
        fclose(fp);
    }
    //如果文件为空，就提示暂无公告
    getc(fp);
    if (feof(fp)) {
        fclose(fp);
        printf("\t\t暂无公告\n");
        Sleep(1500);
        //点击任意键返回
        printf("\t\t单击任意键返回。。。");
        getchar();
        return;
    }
    //如果文件不为空，就读取公告信息
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
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

    //自动生成公告编号
    //获取当前公告数量
    int count = 0;
    while (!feof(fp)) {
        char notice[100];
        fscanf(fp, "%s", notice);
        count++;
    }
    //将公告数量转换为字符串
    char count_str[10];
    sprintf(count_str, "%d", count);
    //将公告编号写入公告结构体
    strcpy(p->notice_num, count_str);
    //放回文件指针
    rewind(fp);

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
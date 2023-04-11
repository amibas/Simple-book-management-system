//
// Created by amiba on 2023/4/10.
//


#include "NoticePort.h"

/*�鿴����*/
void View_Notice() {
    //���ļ��ж�ȡ������Ϣ
    FILE *fp;
    fp = fopen("Notice.txt", "r");
    //��������ڹ����ļ������½�һ��
    if (fp == NULL) {
        fp = fopen("Notice.txt", "w");
        fclose(fp);
    }
    //����ļ�Ϊ�գ�����ʾ���޹���
    getc(fp);
    if (feof(fp)) {
        fclose(fp);
        printf("\t\t���޹���\n");
        Sleep(1500);
        //������������
        printf("\t\t������������ء�����");
        getchar();
        return;
    }
    //����ļ���Ϊ�գ��Ͷ�ȡ������Ϣ
    rewind(fp);
    printf("\t\t�������£�\n");
    while (!feof(fp)) {
        char notice[100];
        fscanf(fp, "%s", notice);
        printf("\t\t%s\n", notice);
    }
}

/**
 * ��������
 */
void Publish_Notice() {
    //�򿪹����ļ�
    Notice *p = (Notice *) malloc(sizeof(Notice));
    FILE *fp;
    fp = fopen("Notice.txt", "a");
    if (fp == NULL) {
        printf("\t\t��ʧ��\n");
        exit(1);
    }

    //�Զ����ɹ�����
    //��ȡ��ǰ��������
    int count = 0;
    while (!feof(fp)) {
        char notice[100];
        fscanf(fp, "%s", notice);
        count++;
    }
    //����������ת��Ϊ�ַ���
    char count_str[10];
    sprintf(count_str, "%d", count);
    //��������д�빫��ṹ��
    strcpy(p->notice_num, count_str);
    //�Ż��ļ�ָ��
    rewind(fp);

    //����
    printf("\t\t�����빫����⣺");
    scanf("%s", p->title);

    //�Զ����ɹ��淢��ʱ��
    time_t t;
    time(&t);
    strcpy(p->notice_num, ctime(&t));

    //����
    printf("\t\t�����빫�����ݣ�");
    scanf("%s", p->notice);

    //��������Ϣд���ļ�
    Save_Notice();
    fclose(fp);
}

/*ɾ������*/
void Delete_Notice() {
    //�������ļ����
    FILE *fp;
    fp = fopen("Notice.txt", "w");
    if (fp == NULL) {
        printf("\t\t��ʧ��\n");
        exit(1);
    }
    fclose(fp);
    printf("\t\tɾ���ɹ�\n");
    Sleep(1500);
}
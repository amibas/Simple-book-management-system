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

/*��������*/
void Publish_Notice() {
    //��������Ϣд���ļ�
    FILE *fp;
    fp = fopen("Notice.txt", "a");
    if (fp == NULL) {
        printf("\t\t��ʧ��\n");
        exit(1);
    }
    printf("\t\t�����빫�����ݣ�");
    char notice[100];
    scanf("%s", notice);
    fprintf(fp, "%s\n", notice);
    fclose(fp);
    printf("\t\t�����ɹ�\n");
    Sleep(1500);
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
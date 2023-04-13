//
// Created by amiba on 2023/4/10.
//


#include "NoticePort.h"
#include "NotClassified.h"


/**
 * ѧ������ҳ��
 */
void studentNotice() {
    char choice = '1';

    while (choice != '0') {
        showStudentNotice();
        printf("\t\t��");
        choice = getchar();
        switch (choice) {
            case '1':
                View_Notice();  //�鿴����
                break;
            case '2':
                findNotice();   //���ҹ���
                break;
            case '0':
                break;          //�˳�
            default:
                printf("\t\t����������������룺");
                Sleep(1500);
                break;
        }
    }
}

/**
 * ��ʾ��ǰ���й���ı�š�����ͷ���ʱ��
 */
void View_Notice() {
    //�򿪹����ļ�
    FILE *fp;
    fp = fopen("Notice.txt", "r");
    if (fp == NULL) {
        printf("\t\t��ʧ��\n");
        exit(1);
    }
    //��ȡ������Ϣ
    Notice *p = Notice_load();
    Notice *q = p;
    //��ʾ������Ϣ
    printf("\t\t������\t\t�������\t\t����ʱ��\n");
    while (q != NULL) {
        printf("\t\t%s\t\t%s\t\t%s\n", q->notice_num, q->title, q->date);
        q = q->next;
    }
    //�޹�����ʾ
    if (p == NULL) {
        printf("\t\t���޹���\n");
    }


    fclose(fp);
    Sleep(1500);
    //���������
    printf("\t\t���������");
    _getch();
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

    //������ַ��Զ����ɹ�����
    RandStr(9, p->notice_num);

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

/*��������*/
void findNotice() {
    //���������Ĺ������
    char title[20];
    printf("\t\t�����빫����⣺");
    scanf("%s", title);
    //�򿪹����ļ�
    FILE *fp;
    fp = fopen("Notice.txt", "r");
    if (fp == NULL) {
        printf("\t\t��ʧ��\n");
        exit(1);
    }
    //���ҹ���
    while (!feof(fp)) {
        char notice[100];
        fscanf(fp, "%s", notice);
        if (strcmp(notice, title) == 0) {
            printf("\t\t%s\n", notice);
            Sleep(1500);
            return;
        }
    }
    printf("\t\tδ�ҵ��ù���\n");
    Sleep(1500);
}
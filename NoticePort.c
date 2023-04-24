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
        scanf("%c", &choice);
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
 * ����Ա����ҳ��
 */
void manageNotice() {
    char choice = '1';

    while (choice != '0') {
        while (getchar() != '\n');  //��ջ�����
        showManagerNotice();
        printf("\t\t��");
        scanf("%c", &choice);
        switch (choice) {
            case '1':
                View_Notice();      //�鿴����
                break;
            case '2':
                Publish_Notice();   //��������
                break;
            case '3':
                Delete_Notice();    //ɾ������
                break;
            case '4':
                findNotice();       //���ҹ���
                break;
            case '0':
                break;              //�˳�
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
    //����ͷ
    Notice *p = Notice_head;
    //��ӡ������Ϣ
    printf("\t\t������\t\t�������\t\t����ʱ��\n");
    while (p->next != NULL) {
        p = p->next;
        printf("\t\t%s\t\t%s\t\t%s\n", p->notice_num, p->title, p->date);
    }
    //�����Ų鿴��������,����0����
    printf("\t\t��������Ҫ�鿴�Ĺ�����(����0����)��");
    char num[10];
    scanf("%s", num);
    if (strcmp(num, "0") == 0) {
        return;
    }
    //���ҹ���
    p = Notice_head;
    while (p->next != NULL) {
        p = p->next;
        if (strcmp(p->notice_num, num) == 0) {
            printf("\t\t�����ţ�%s\n", p->notice_num);
            printf("\t\t������⣺%s\n", p->title);
            printf("\t\t�������ݣ�%s\n", p->notice);
            printf("\t\t����ʱ�䣺%s\n", p->date);
            printf("\t\t���������");
            _getch();
            return;
        }
    }
    if (p->next == NULL) {
        printf("\t\tû���ҵ��ù���\n");
    }
    //���������
    printf("\t\t���������");
    _getch();
}

/**
 * ��������
 */
void Publish_Notice() {
    //����ͷ
    Notice *p = Notice_head;
    //�ƶ�������β
    while (p->next != NULL) {
        p = p->next;
    }
    //�����½ڵ�
    Notice *new = (Notice *) malloc(sizeof(Notice));
    new->next = NULL;
    //���빫����Ϣ
    printf("\t\t�����빫����⣺");
    strcmp(new->title, '\0');
    scanf("%s", new->title);
    printf("\t\t�����빫�����ݣ�");
    strcmp(new->notice, '\0');
    scanf("%s", new->notice);
    //���ɹ�����
    strcmp(new->notice_num, '\0');
    RandStr(8, new->notice_num);
    //���ɷ���ʱ��
    int i = 0;
    time_t tt = time(0);
    //������YYYY-MM-DD-hh:mm:ss����ʽ���ַ�����
    char s[32];
    strftime(s, sizeof(s), "%Y-%m-%d-%H:%M:%S", localtime(&tt));
    //s[i] = '\n';
    s[31] = '\n';
    strcpy(new->date, s);
    //���½ڵ��������
    p->next = new;
    //��������Ϣд���ļ�
    Save_Notice();
    printf("\t\t�����ɹ�\n");
    Sleep(1500);
}

/*ɾ������*/
void Delete_Notice() {
}

/*��������*/
void findNotice() {
    //���������Ĺ������
    char title[20];
    printf("\t\t�����빫����⣺");
    scanf("%s", title);
    //�򿪹����ļ�
    FILE *fp;
    fp = fopen("Notice.dat", "r");
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
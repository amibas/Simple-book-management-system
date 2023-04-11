//
// Created by amiba on 2023/4/2.
//

#include "DataManagement.h"


Book *Book_head;
Student *Student_head;
Manager *Manager_head;
Notice *Notice_head;


Book *Book_load() {
    FILE *fp;
    Book *h = NULL, *t = h, *p;
    if ((fp = fopen("Booknode.txt", "r")) == NULL) {
        printf("\t\t��ʧ��\n");
        exit(1);
    }
    getc(fp);
    if (feof(fp)) {
        fclose(fp);
        return NULL;
    }
    rewind(fp);
    while (!feof(fp)) {
        p = (Book *) malloc(sizeof(Book));
        p->next = NULL;
        fscanf(fp, "%s", p->book_num);
        fscanf(fp, "%s", p->book_name);
        fscanf(fp, "%s", p->book_at_name);
        fscanf(fp, "%s", p->book_cp_name);
        fscanf(fp, "%f", &p->book_price);
        fscanf(fp, "%d", &p->book_rest);
        if (h == NULL)
            h = p;
        else
            t->next = p;
        t = p;
    }
    fclose(fp);
    return h;
}

/*��ѧ���ļ��е���Ϣ������ѧ������*/
Student *Student_load(void) {
    FILE *fp;
    Student *h = NULL, *t = h, *p;
    if ((fp = fopen("Studentnode.txt", "r")) == NULL) {
        printf("\t\t��ʧ��\n");
        exit(1);
    }
    getc(fp);
    if (feof(fp)) {
        fclose(fp);
        return NULL;
    }
    rewind(fp);
    while (!feof(fp)) {
        p = (Student *) malloc(sizeof(Student));
        p->next = NULL;
        fscanf(fp, "%s", p->stu_acc);
        fscanf(fp, "%s", p->stu_passw);
        fscanf(fp, "%s", p->stu_find_question);
        fscanf(fp, "%s", p->stu_find_passw);
        fscanf(fp, "%s", p->stu_num);
        fscanf(fp, "%s", p->stu_name);
        fscanf(fp, "%s", p->stu_tel);
        for (int i = 0; i < 10; i++) {
            fscanf(fp, "%s", p->stu_bor_book[i]);
        }
        int len = strlen(p->stu_passw);            //�������
        for (int i = 0; i < len; i++) {
            p->stu_passw[i] = p->stu_passw[i] - (i % 4 + 1);
        }
        len = strlen(p->stu_find_passw);            //�ܱ��������
        for (int i = 0; i < len; i++) {
            p->stu_find_passw[i] = p->stu_find_passw[i] - (i % 4 + 1);
        }
        if (h == NULL)
            h = p;
        else
            t->next = p;
        t = p;
    }
    fclose(fp);
    return h;
}

Manager *Manager_load(void) {
    FILE *fp;
    Manager *h = NULL, *t = h, *p;
    if ((fp = fopen("Managernode.txt", "r")) == NULL) {
        printf("\t\t��ʧ��\n");
        exit(1);
    }
    getc(fp);
    if (feof(fp)) {
        fclose(fp);
        return NULL;
    }
    rewind(fp);
    while (!feof(fp)) {
        p = (Manager *) malloc(sizeof(Manager));
        p->next = NULL;
        fscanf(fp, "%s", p->man_name);
        fscanf(fp, "%s", p->man_acc);
        fscanf(fp, "%s", p->man_passw);
        int len = strlen(p->man_passw);            //�������
        for (int i = 0; i < len; i++) {
            p->man_passw[i] = p->man_passw[i] - (i % 4 + 1);

        }
        if (h == NULL)
            h = p;
        else
            t->next = p;
        t = p;
    }
    fclose(fp);
    return h;
}

/*�����鼮�������ļ�*/
void Save_Book(void) {
    FILE *fp;
    Book *t = Book_head->next;
    if (!t)
        return;
    if ((fp = fopen("Booknode.txt", "w+")) == NULL) {
        printf("\t\t��ʧ��\n");
        exit(1);
    }
    while (t->next) {
        fprintf(fp, "%s ", t->book_num);
        fprintf(fp, "%s ", t->book_name);
        fprintf(fp, "%s ", t->book_at_name);
        fprintf(fp, "%s ", t->book_cp_name);
        fprintf(fp, "%.2f ", t->book_price);
        fprintf(fp, "%d\n", t->book_rest);
        t = t->next;
    }
    fprintf(fp, "%s ", t->book_num);
    fprintf(fp, "%s ", t->book_name);
    fprintf(fp, "%s ", t->book_at_name);
    fprintf(fp, "%s ", t->book_cp_name);
    fprintf(fp, "%.2f ", t->book_price);
    fprintf(fp, "%d", t->book_rest);
    fclose(fp);
}

/*����ѧ���������ļ�*/
void Save_Student(void) {
    FILE *fp;
    Student *t = Student_head->next;
    if (!t)
        return;
    if ((fp = fopen("Studentnode.txt", "w+")) == NULL) {
        printf("\t\t��ʧ��\n");
        exit(1);
    }
    while (t->next) {
        int len = strlen(t->stu_passw);            //�������
        for (int i = 0; i < len; i++) {
            t->stu_passw[i] = t->stu_passw[i] + (i % 4 + 1);
        }
        len = strlen(t->stu_find_passw);            //�ܱ��������
        for (int i = 0; i < len; i++) {
            t->stu_find_passw[i] = t->stu_find_passw[i] + (i % 4 + 1);
        }
        fprintf(fp, "%s ", t->stu_acc);
        fprintf(fp, "%s ", t->stu_passw);
        fprintf(fp, "%s ", t->stu_find_question);
        fprintf(fp, "%s ", t->stu_find_passw);
        fprintf(fp, "%s ", t->stu_num);
        fprintf(fp, "%s ", t->stu_name);
        fprintf(fp, "%s ", t->stu_tel);
        for (int i = 0; i < 9; i++) {
            fprintf(fp, "%s ", t->stu_bor_book[i]);
        }
        fprintf(fp, "%s\n", t->stu_bor_book[9]);
        t = t->next;
    }

    int len = strlen(t->stu_passw);            //�������
    for (int i = 0; i < len; i++) {
        t->stu_passw[i] = t->stu_passw[i] + (i % 4 + 1);
    }
    len = strlen(t->stu_find_passw);            //�ܱ��������
    for (int i = 0; i < len; i++) {
        t->stu_find_passw[i] = t->stu_find_passw[i] + (i % 4 + 1);
    }
    fprintf(fp, "%s ", t->stu_acc);
    fprintf(fp, "%s ", t->stu_passw);
    fprintf(fp, "%s ", t->stu_find_question);
    fprintf(fp, "%s ", t->stu_find_passw);
    fprintf(fp, "%s ", t->stu_num);
    fprintf(fp, "%s ", t->stu_name);
    fprintf(fp, "%s ", t->stu_tel);
    for (int i = 0; i < 9; i++) {
        fprintf(fp, "%s ", t->stu_bor_book[i]);
    }
    fprintf(fp, "%s", t->stu_bor_book[9]);
    fclose(fp);

}

/*�������Ա�������ļ�*/
void Save_Manger(void) {
    FILE *fp;
    Manager *t = Manager_head->next;
    if (!t)
        return;
    if ((fp = fopen("Managernode.txt", "w+")) == NULL) {
        printf("\t\t��ʧ��\n");
        exit(1);
    }
    while (t->next) {
        int len = strlen(t->man_passw);            //�������
        for (int i = 0; i < len; i++) {
            t->man_passw[i] = t->man_passw[i] + (i % 4 + 1);
        }
        fprintf(fp, "%s ", t->man_name);
        fprintf(fp, "%s ", t->man_acc);
        fprintf(fp, "%s\n", t->man_passw);
        t = t->next;
    }
    int len = strlen(t->man_passw);            //�������
    for (int i = 0; i < len; i++) {
        t->man_passw[i] = t->man_passw[i] + (i % 4 + 1);
    }
    fprintf(fp, "%s ", t->man_name);
    fprintf(fp, "%s ", t->man_acc);
    fprintf(fp, "%s", t->man_passw);
    fclose(fp);
}

//��ȡ����
Notice *Notice_load(void){
    FILE *fp;
    Notice *h = NULL, *t = NULL, *p;
    if ((fp = fopen("Notice.txt", "r")) == NULL) {
        printf("\t\t��ʧ��\n");
        exit(1);
    }
    getc(fp);
    if (feof(fp)) {
        fclose(fp);
        return NULL;
    }
    rewind(fp);
    while (!feof(fp)) {
        p = (Notice *)malloc(sizeof(Notice));
        p->next = NULL;
        fscanf(fp, "%s", p->notice_num);
        fscanf(fp, "%s", p->date);
        fscanf(fp, "%s", p->title);
        fscanf(fp, "%s", p->notice);
    }
}

/**
 * ���湫��
 */
void Save_Notice(void){
    FILE *fp;
    Notice *t = Notice_head->next;
    if (!t)
        return;
    if ((fp = fopen("Notice.txt", "w+")) == NULL) {
        printf("\t\t��ʧ��\n");
        exit(1);
    }
    while (t->next) {
        fprintf(fp, "%s ", t->notice_num);
        fprintf(fp, "%s ", t->date);
        fprintf(fp, "%s ", t->title);
        fprintf(fp, "%s", t->notice);
        t = t->next;
    }
    fclose(fp);
}

/*������Ϣ�������ļ�*/
void Massage_Save(void) {
    Save_Book();
    Save_Student();
    Save_Notice();
    Save_Manger();
}
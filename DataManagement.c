//
// Created by amiba on 2023/4/2.
//

#include "DataManagement.h"


Book *Book_head;
Student *Student_head;
Manager *Manager_head;
Notice *Notice_head;


/**
 * 获取书籍数量
 */
int getBookCount() {
    Book *p = Book_head;
    int count = 0;
    while (p != NULL) {
        count += p->book_rest;
        p = p->next;
    }
    return count;
}

/**
 * 载入书籍信息
 * @return bookHead
 */
Book *Book_load() {
    FILE *fp;
    Book *h = NULL, *t = h, *p;
    if ((fp = fopen("Booknode.txt", "r")) == NULL) {
        printf("\t\t打开失败\n");
        exit(1);
    }
    getc(fp);
    if (feof(fp)) {
        fclose(fp);
        return NULL;
    }
    rewind(fp); //将文件指针指向文件开头
    while (!feof(fp)) { //判断文件是否结束
        p = (Book *) malloc(sizeof(Book));
        p->next = NULL;
        //将文件中的信息读取到结构体中
        fscanf(fp, "%s", p->book_num);
        fscanf(fp, "%s", p->book_name);
        fscanf(fp, "%s", p->book_at_name);
        fscanf(fp, "%s", p->book_cp_name);
        fscanf(fp, "%f", &p->book_price);
        fscanf(fp, "%d", &p->book_rest);
        if (h == NULL)  //如果是第一个结点
            h = p;
        else            //如果不是第一个结点
            t->next = p;
        t = p;
    }
    fclose(fp);
    return h;
}

/*将学生文件中的信息加载至学生链表*/
Student *Student_load(void) {
    FILE *fp;
    Student *h = NULL, *t = h, *p;
    if ((fp = fopen("Studentnode.txt", "r")) == NULL) {
        printf("\t\t打开失败\n");
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
        //将文件中的信息读取到结构体中
        fscanf(fp, "%s", p->stu_acc);
        fscanf(fp, "%s", p->stu_passw);
        fscanf(fp, "%s", p->stu_find_question);
        fscanf(fp, "%s", p->stu_find_passw);
        fscanf(fp, "%s", p->stu_num);
        fscanf(fp, "%s", p->stu_name);
        fscanf(fp, "%s", p->stu_tel);
        for (int i = 0; i < 10; i++) {                                  //读取学生借阅的书籍
            fscanf(fp, "%s", p->stu_bor_book[i]);
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

/*载入管理员*/
Manager *Manager_load(void) {
    FILE *fp;
    Manager *h = NULL, *t = h, *p;
    if ((fp = fopen("Managernode.txt", "r")) == NULL) {
        printf("\t\t打开失败\n");
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
        if (h == NULL)
            h = p;
        else
            t->next = p;
        t = p;
    }
    fclose(fp);
    return h;
}

/*保存书籍链表至文件*/
void Save_Book(void) {
    FILE *fp;
    Book *t = Book_head->next;
    if (!t)
        return;
    if ((fp = fopen("Booknode.txt", "w+")) == NULL) {
        printf("\t\t打开失败\n");
        exit(1);
    }
    //将链表中的信息写入文件
    while (t->next) {
        fprintf(fp, "%s ", t->book_num);
        fprintf(fp, "%s ", t->book_name);
        fprintf(fp, "%s ", t->book_at_name);
        fprintf(fp, "%s ", t->book_cp_name);
        fprintf(fp, "%.2f ", t->book_price);
        fprintf(fp, "%d\n", t->book_rest);
        t = t->next;
    }
    //将最后一个结点的信息写入文件
    fprintf(fp, "%s ", t->book_num);
    fprintf(fp, "%s ", t->book_name);
    fprintf(fp, "%s ", t->book_at_name);
    fprintf(fp, "%s ", t->book_cp_name);
    fprintf(fp, "%.2f ", t->book_price);
    fprintf(fp, "%d", t->book_rest);
    fclose(fp);
}

/*保存学生链表至文件*/
void Save_Student(void) {
    FILE *fp;
    Student *t = Student_head->next;
    if (!t)
        return;
    if ((fp = fopen("Studentnode.txt", "w+")) == NULL) {
        printf("\t\t打开失败\n");
        exit(1);
    }
    while (t->next) {
        //将链表中的信息写入文件
        fprintf(fp, "%s ", t->stu_acc);
        fprintf(fp, "%s ", t->stu_passw);
        fprintf(fp, "%s ", t->stu_find_question);
        fprintf(fp, "%s ", t->stu_find_passw);
        fprintf(fp, "%s ", t->stu_num);
        fprintf(fp, "%s ", t->stu_name);
        fprintf(fp, "%s ", t->stu_tel);
        //将学生借阅的书籍写入文件
        for (int i = 0; i < 9; i++) {
            fprintf(fp, "%s ", t->stu_bor_book[i]);
        }
        fprintf(fp, "%s\n", t->stu_bor_book[9]);
        t = t->next;
    }
    //将链表中的信息写入文件
    fprintf(fp, "%s ", t->stu_acc);
    fprintf(fp, "%s ", t->stu_passw);
    fprintf(fp, "%s ", t->stu_find_question);
    fprintf(fp, "%s ", t->stu_find_passw);
    fprintf(fp, "%s ", t->stu_num);
    fprintf(fp, "%s ", t->stu_name);
    fprintf(fp, "%s ", t->stu_tel);
    //将学生借阅的书籍写入文件
    for (int i = 0; i < 9; i++) {
        fprintf(fp, "%s ", t->stu_bor_book[i]);
    }
    fprintf(fp, "%s", t->stu_bor_book[9]);
    fclose(fp);

}

/*保存管理员链表至文件*/
void Save_Manger(void) {
    FILE *fp;
    Manager *t = Manager_head->next;
    if (!t)
        return;
    if ((fp = fopen("Managernode.txt", "w+")) == NULL) {
        printf("\t\t打开失败\n");
        exit(1);
    }

    while (t->next) {
        fprintf(fp, "%s ", t->man_name);
        fprintf(fp, "%s ", t->man_acc);
        fprintf(fp, "%s\n", t->man_passw);
        t = t->next;
    }

    //将链表中的信息写入文件
    fprintf(fp, "%s ", t->man_name);
    fprintf(fp, "%s ", t->man_acc);
    fprintf(fp, "%s", t->man_passw);
    fclose(fp);
}

/*读取公告*/
Notice *Notice_load(void) {
    FILE *fp;
    Notice *h = NULL, *t = h, *p;
    if ((fp = fopen("Notice.txt", "r")) == NULL) {
        //创建文件
        fp = fopen("Notice.txt", "w+");
        fclose(fp);
        Notice_load();
    }
    getc(fp);
    if (feof(fp)) {
        fclose(fp);
        return NULL;
    }
    rewind(fp);

    p = (Notice *) malloc(sizeof(Notice));
    while (fscanf(fp, "%s %s %s %s", p->notice_num, p->date, p->title, p->notice) != EOF) {
        p->next = NULL;
        if (h == NULL)
            h = p;
        else
            t->next = p;
        t = p;
        p = (Notice *) malloc(sizeof(Notice));
    }
    fclose(fp);
    return h;
}

/*保存公告*/
void Save_Notice(void) {
    FILE *fp;
    Notice *t = Notice_head->next;
    if (!t)
        return;
    if ((fp = fopen("Notice.txt", "w+")) == NULL) {
        printf("\t\t打开失败\n");
        exit(1);
    }
    fseek(fp, 0, 1);
    while (t != NULL) {
        fprintf(fp, "%s %s %s %s\n", t->notice_num, t->date, t->title, t->notice);
        t = t->next;
    }

    fclose(fp);
}

/*所有信息保存至文件*/
void Massage_Save(void) {
    Save_Book();
    Save_Student();
    Save_Notice();
    Save_Manger();
}
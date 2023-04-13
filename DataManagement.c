//
// Created by amiba on 2023/4/2.
//

#include "DataManagement.h"


Book *Book_head;
Student *Student_head;
Manager *Manager_head;
Notice *Notice_head;


/*根据stu_bor_book设置每人的借书数量*/
void setBorrowCount() {
    Student *p = Student_head;
    while (p != NULL) {
        int count = 0;
        for (int i = 0; i < 10; i++) {
            if (strcmp(p->stu_bor_book[i], "0") != 0)
                count++;
        }
        p->stu_bor_count = count;
        p = p->next;
    }
}

/*借书最多的人的学号*/
char *getMostBorrower() {
    Student *p = Student_head;
    int max = 0;
    char *num = (char *) malloc(sizeof(char) * 20);
    setBorrowCount();
    while (p != NULL) {
        int count = p->stu_bor_count;
        if (count > max) {
            max = count;
            strcpy(num, p->stu_num);
        }
        p = p->next;
    }
    return num;
}

/*获取书籍数量*/
int getBookCount() {
    Book *p = Book_head;
    int count = 0;
    while (p != NULL) {
        count += p->book_rest;
        p = p->next;
    }
    return count;
}

/*载入书籍 */
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

//        int len = strlen(p->stu_passw);                             //密码解密
//        for (int i = 0; i < len; i++) {
//            p->stu_passw[i] = p->stu_passw[i] - (i % 4 + 1);
//        }

//        len = strlen(p->stu_find_passw);                            //密保密码解密
//        for (int i = 0; i < len; i++) {
//            p->stu_find_passw[i] = p->stu_find_passw[i] - (i % 4 + 1);
//        }

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
//        int len = strlen(p->man_passw);                     //密码解密
//        for (int i = 0; i < len; i++) {
//            p->man_passw[i] = p->man_passw[i] - (i % 4 + 1);
//
//        }
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
//        int len = strlen(t->stu_passw);                                 //密码加密
//        for (int i = 0; i < len; i++) {
//            t->stu_passw[i] = t->stu_passw[i] + (i % 4 + 1);
//        }
//
//        len = strlen(t->stu_find_passw);                                //密保密码加密
//        for (int i = 0; i < len; i++) {
//            t->stu_find_passw[i] = t->stu_find_passw[i] + (i % 4 + 1);
//        }
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
    //将最后一个结点的信息写入文件
//    int len = strlen(t->stu_passw);                                     //密码加密
//    for (int i = 0; i < len; i++) {
//        t->stu_passw[i] = t->stu_passw[i] + (i % 4 + 1);
//    }
//
//    len = strlen(t->stu_find_passw);                                    //密保密码加密
//    for (int i = 0; i < len; i++) {
//        t->stu_find_passw[i] = t->stu_find_passw[i] + (i % 4 + 1);
//    }
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
//        int len = strlen(t->man_passw);                     //密码加密
//        for (int i = 0; i < len; i++) {
//            t->man_passw[i] = t->man_passw[i] + (i % 4 + 1);
//        }
        fprintf(fp, "%s ", t->man_name);
        fprintf(fp, "%s ", t->man_acc);
        fprintf(fp, "%s\n", t->man_passw);
        t = t->next;
    }

//    int len = strlen(t->man_passw);                         //密码加密
//    for (int i = 0; i < len; i++) {
//        t->man_passw[i] = t->man_passw[i] + (i % 4 + 1);
//    }
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
    if ((fp = fopen("Notice.dat", "r")) == NULL) {
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
        p = (Notice *) malloc(sizeof(Notice));
        p->next = NULL;
//        fscanf(fp, "%s ", p->notice_num);
//        fscanf(fp, "%s ", p->date);
//        fscanf(fp, "%s ", p->title);
//        fscanf(fp, "%s\n", p->notice);
        fread(p, sizeof(Notice), 1, fp);
        if (h == NULL)
            h = p;
        else
            t->next = p;
        t = p;
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
    if ((fp = fopen("Notice.dat", "w+")) == NULL) {
        printf("\t\t打开失败\n");
        exit(1);
    }
    while (t->next) {

//        fscanf(fp, "%s ", t->notice_num);
//        fscanf(fp, "%s ", t->date);
//        fscanf(fp, "%s ", t->title);
//        fscanf(fp, "%s\n", t->notice);
        fwrite(t, sizeof(Notice), 1, fp);
        t = t->next;
    }


    //将链表尾中的信息写入文件
//    fscanf(fp, "%s ", t->notice_num);
//    fscanf(fp, "%s ", t->date);
//    fscanf(fp, "%s ", t->title);
//    fscanf(fp, "%s", t->notice);
    fwrite(t, sizeof(Notice), 1, fp);

    fclose(fp);
}

/*所有信息保存至文件*/
void Massage_Save(void) {
    Save_Book();
    Save_Student();
    Save_Notice();
    Save_Manger();
}
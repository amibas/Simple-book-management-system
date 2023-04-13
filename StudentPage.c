//
// Created by amiba on 2023/4/3.
//

#include "StudentPage.h"

void Find_Book(void) {
    while (getchar() != '\n');  //��ջ�����
    Book *t = Book_head->next;
    char book_n[20];
    if (t == NULL) {
        printf("\t\t��Ǹ�������鼮\n");
        printf("\t\t��������˳�");
        getch();
        return;
    }
    printf("\t\t����������Ҫ���ҵ�������");
    gets(book_n);
    while (t) {
        if (strcmp(book_n, t->book_name) == 0)
            break;
        t = t->next;
    }
    if (t == NULL) {
        printf("\t\t��Ǹ���޴��鼮\n");
        printf("\t\t��������˳�");
        getch();
        return;
    }
    t = Book_head->next;
    printf("\n\n\t**********************************");
    printf("********************************\n\n");
    printf("\t %-8s%-12s%-12s%-18s%-10s%-8s\n\n",
           "���", "����", "����", "������", "�۸�", "���");
    while (t) {
        if (strcmp(book_n, t->book_name) == 0)
            printf("\t %-8s%-12s%-12s%-18s%-10.2f%-8d\n",
                   t->book_num, t->book_name, t->book_at_name,
                   t->book_cp_name, t->book_price, t->book_rest);
        t = t->next;
    }
    printf("\n\t**************************************");
    printf("****************************\n\n\n");
    printf("\n\t\t��������˳�");
    getch();

}

Book *Find_BookofName(char *Book_num) {
    Book *t = Book_head->next;
    while (t) {
        if (strcmp(Book_num, t->book_num) == 0)
            return t;
        t = t->next;
    }
}

void Change_Stupassword(Student *Stu_num) {
    while (getchar() != '\n');  //��ջ�����
    char password_tem[20];
    printf("\t\t�����С�����\n");
    Sleep(500);
    printf("\t\t������ԭ���룺");
    if (Password_Text_Find(Stu_num->stu_passw) == 0) {
        printf("\n\t\t�Ѿ����������������Σ����˳��޸�����ϵͳ������\n");
        Sleep(1500);
        return;
    }
    printf("\n\t\t��֤�С�����\n");
    Sleep(1000);
    printf("\t\t��֤�ɹ���\n");
    Sleep(500);
    printf("\t\t������������(6~10λ)��");
    Password_Input(password_tem);
    printf("\n\t\t���ٴ����������룺");
    if (Password_Text(password_tem) == 0) {
        printf("\t\t�Ѿ����������������Σ����˳��޸�����ϵͳ������\n");
        Sleep(3000);
        return;
    }
    Stu_num->stu_passw[0] = '\0';
    strcat(Stu_num->stu_passw, password_tem);
    Sleep(500);
    printf("\n\t\t���Եȣ������޸ġ�����\n");
    Sleep(1000);
    printf("\t\t������\n");
    Sleep(1000);
    printf("\t\t������\n");
    Sleep(1000);
    printf("\t\t��ϲ���޸ĳɹ���\n");
    printf("\t\t��������˳�");
    getch();
}

void Find_Theborrow(Student *Stu_num) {
    while (getchar() != '\n');  //��ջ�����
    int tem = 0;
    Book *t;
    printf("\t\t�����С�����\n");
    Sleep(1000);
    for (int i = 0; i < 10; i++) {
        if (strcmp(Stu_num->stu_bor_book[i], "0") != 0) {
            tem = 1;
            break;
        }
    }
    if (tem == 0) {
        printf("\t\t���޽����¼\n");
        printf("\t\t��������˳�");
        getch();
        return;
    }
    printf("\n\n\t*************************");
    printf("********************************\n\n");
    printf("\t %-8s%-12s%-12s%-18s%-10s\n\n",
           "���", "����", "����", "������", "�۸�");
    for (int i = 0; i < 10; i++) {
        if (strcmp(Stu_num->stu_bor_book[i], "0") != 0) {
            t = Find_BookofName(Stu_num->stu_bor_book[i]);
            printf("\t %-8s%-12s%-12s%-18s%-10.2f\n",
                   t->book_num, t->book_name, t->book_at_name,
                   t->book_cp_name, t->book_price);
        }
    }
    printf("\n\t*****************************");
    printf("****************************\n\n\n");
    printf("\n\t\t��������˳�");
    getch();
}

void Stu_Borrow(Student *Stu_num) {
    int n = 0;
    Book *t;
    char numb[10];
    while (getchar() != '\n');  //��ջ�����
    for (int i = 0; i < 10; i++) {
        if (strcmp(Stu_num->stu_bor_book[i], "0") != 0)
            n++;
    }
    printf("\n\t\t��ӭ�������ϵͳ\n");
    printf("\n\t\t�����С�����\n");
    Sleep(1000);
    if (n == 10) {
        printf("\t\t���ã����ѽ���10�����ѵ��������޶");
        printf("\t\t���ȹ黹�ѽ��鼮\n\n");
        printf("\t\t��������˳�");
        getch();
        return;
    }
    printf("\t\t���ѽ��鼮%d�������ɽ�%d��\n", n, 10 - n);
    printf("\t\t�鵥����\n");
    Print_Book();
    printf("\n\t\t��ѡ���������ı�ţ�");
    gets(numb);
    t = Book_exit(numb);
    printf("\t\t���ڰ�������\n");
    Sleep(1000);
    if (!t) {
        printf("\t\t��Ǹ���޴��飬����ʧ��\n");
        printf("\t\t��������˳�");
        getch();
        return;
    }
    if (t->book_rest == 0) {
        printf("\t\t��Ǹ����治�㣬����ʧ��\n");
        printf("\t\t��������˳�");
        getch();
        return;
    }
    if (Ifborrow(Stu_num, numb)) {
        printf("\t\t��Ǹ�����ѽ�����飬�����ظ�����\n");
        printf("\t\t��������˳�");
        getch();
        return;
    }
    for (int i = 0; i < 10; i++) {
        if (strcmp(Stu_num->stu_bor_book[i], "0") == 0) {
            Stu_num->stu_bor_book[i][0] = '\0';
            strcat(Stu_num->stu_bor_book[i], numb);
            t->book_rest--;
            break;
        }
    }
    printf("\t\t������\n");
    printf("\t\t��ϲ������ɹ���\n");
    printf("\t\t��������˳�");
    getch();
    return;
}

/*��ӡ�鵥*/
void Print_Book(void) {
    Book *t = Book_head->next;
    if (t == NULL) {
        printf("\t\t��Ǹ�������ϼ��鼮\n");
        Sleep(2000);
        return;
    }
    printf("\n\n\t**********************************");
    printf("********************************\n\n");
    printf("\t %-8s%-12s%-12s%-18s%-10s%-8s\n\n",
           "���", "����", "����", "������", "�۸�", "���");
    while (t) {
        printf("\t %-8s%-12s%-12s%-18s%-10.2f%-8d\n",
               t->book_num, t->book_name, t->book_at_name,
               t->book_cp_name, t->book_price, t->book_rest);
        t = t->next;
    }
    printf("\n\t**************************************");
    printf("****************************\n\n\n");
}

/*Ѱ�Ҹ����Ƿ����*/
Book *Book_exit(char *Book_num) {

    Book *t = Book_head->next;
    while (t) {
        if (strcmp(t->book_num, Book_num) == 0)
            break;
        t = t->next;
    }
    return t;
}

/*��ѯѧ���Ƿ�������*/
int Ifborrow(Student *Stu_num, char *Book_num) {
    int tem = 0;
    for (int i = 0; i < 10; i++) {
        if (strcmp(Stu_num->stu_bor_book[i], Book_num) == 0) {
            tem = 1;
            break;
        }
    }
    return tem;
}

/*ѧ������*/
void Stu_Back(Student *Stu_num) {
    char book_num[15];
    int tem = 0;
    printf("\n\t\t��ӭ���뻹��ϵͳ\n");
    printf("\n\t\t�����С�����\n");
    Sleep(500);
    printf("\n\t\t���ڲ����ѽ��鼮������\n");
    Sleep(500);
    for (int i = 0; i < 10; i++) {
        if (strcmp(Stu_num->stu_bor_book[i], "0") != 0) {
            tem = 1;
            break;
        }
    }
    if (tem == 0) {
        printf("\n\t\t���޽����¼\n");
        printf("\n\t\t��������˳�");
        getch();
        return;
    }
    Print_Borbook(Stu_num);
    printf("\n\t\t��������ı�Ž��й黹��");
    gets(book_num);
    tem = 0;
    for (int i = 0; i < 10; i++) {
        if (strcmp(Stu_num->stu_bor_book[i], book_num) == 0) {
            tem = 1;
            break;
        }
    }
    if (!tem) {
        printf("\t\t���������δ�������\n");
        printf("\t\t��������˳�");
        getch();
        return;
    }

    Sleep(500);
    printf("\t\t���ڹ黹������\n");
    Sleep(500);
    Bake_Book(Stu_num, book_num);
    printf("\t\t�黹�ɹ���\n");
    printf("\t\t��������˳�");
    getch();
}

/*��ӡ�����鼮*/
void Print_Borbook(Student *Stu_num) {

    int tem = 0;
    Book *t;
    printf("\n\n\t*************************");
    printf("********************************\n\n");
    printf("\t %-8s%-12s%-12s%-18s%-10s\n\n",
           "���", "����", "����", "������", "�۸�");
    for (int i = 0; i < 10; i++) {
        if (strcmp(Stu_num->stu_bor_book[i], "0") != 0) {
            t = Find_BookofName(Stu_num->stu_bor_book[i]);
            printf("\t %-8s%-12s%-12s%-18s%-10.2f\n",
                   t->book_num, t->book_name, t->book_at_name,
                   t->book_cp_name, t->book_price);
        }
    }
    printf("\n\t*****************************");
    printf("****************************\n\n\n");
}

/*����������*/
void Bake_Book(Student *Stu_num, char *Book_num) {
    Book *t;
    for (int i = 0; i < 10; i++) {
        if (strcmp(Stu_num->stu_bor_book[i], Book_num) == 0) {
            Stu_num->stu_bor_book[i][0] = '0';
            Stu_num->stu_bor_book[i][1] = '\0';
            break;
        }
    }
    t = Find_BookofName(Book_num);
    t->book_rest++;
}
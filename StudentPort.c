//
// Created by amiba on 2023/4/3.
//

#include "StudentPort.h"


/**
 * ѧ����
 */
void Student_Port(void) {
    char sp = '1';  //ѧ����ѡ��

    //ѧ���˽���
    while (sp != '0') {
        show_stu(); //��ʾѧ���˽���
        printf("\t\t\t��");

        scanf("%c", &sp);   //����ѡ��
        //�ж�ѡ��
        switch (sp) {
            case '1':
                Student_Login();    //ѧ����¼
                break;
            case '2':
                Student_Register(); //ѧ��ע��
                break;
            case '3':
                Find_Password();    //�һ�����
                break;
            case '0':
                break;  //�˳�
            default:    //�������
                printf("\t\t����������������룺\n");
                Sleep(1500);
                break;
        }
        while (getchar() != '\n');  //��ջ�����
    }
}

/**
 * ѧ��ע��
 */
void Student_Register(void) {
    //��ʼ������
    Student *t; //��ʱָ��
    Student *new = (Student *) malloc(sizeof(Student)); //�½ڵ�
    new->next = NULL;   //�½ڵ�ָ�����ÿ�

    //��ʼ���½ڵ�
    for (int i = 0; i < 10; i++) {
        new->stu_bor_book[i][0] = '0';
        new->stu_bor_book[i][1] = '\0';
    }

    //ע�����
    printf("\n\t\t��ӭ����ע��ϵͳ��\n");
    Sleep(500);
    printf("\t\t���ڼ��ء�����\n");
    Sleep(500);
    printf("\t\t������������Ϣ\n");
    printf("\t\tѧ�ţ�");
    scanf("%s", new->stu_num);
    printf("\t\t������");
    scanf("%s", new->stu_name);
    printf("\t\t�绰��");
    scanf("%s", new->stu_tel);
    printf("\t\t���룺");
    Password_Input(new->stu_passw);
    printf("\n\t\t�ٴ��������룺");
    //�ж������Ƿ���ȷ
    if (Password_Text(new->stu_passw) == 0) {
        printf("\n\t\t�����������3�Σ����˳�ע��ϵͳ������");
        Sleep(5000);
        free(new);
        return;
    }

    //�ܱ�����
    printf("\n\n\t\t�ܱ����������һ�����\n");
    printf("\t\t�磺\n");
    printf("\t\t    ��ĸ�׵������ǣ�\n");
    printf("\t\t    �Ҹ��׵������ǣ�\n");
    printf("\t\t    �ҵ������ǣ�\n");
    printf("\n\t\t�ܱ����⣺");
    scanf("%s", new->stu_find_question);
    printf("\t\t�ܱ��������룺");
    Password_Input(new->stu_find_passw);
    printf("\n\t\t�ٴ������ܱ��������룺");
    if (Password_Text(new->stu_find_passw) == 0) {
        printf("\n\t\t�����������3�Σ����˳�ע��ϵͳ������");
        Sleep(5000);
        free(new);
        return;
    }

    //ע��ɹ�
    Sleep(500);
    printf("\n\t\t����ע�ᡤ����\n");
    Sleep(1000);
    printf("\t\t������\n");
    Sleep(1000);
    printf("\t\t������\n");
    Sleep(1000);
    printf("\t\tע��ɹ���\n");
    RandStr(6, new->stu_acc);
    printf("\t\t�����˺���: %s\n", new->stu_acc);
    printf("\t\t������μ��˺����룡\n");
    while (getchar() != '\n');
    t = Student_head;   //��ʱָ��ָ��ͷ�ڵ�
    while (t->next) {   //��������
        t = t->next;
    }
    t->next = new;      //���½ڵ��������

    //��������˳�
    printf("\t\t��������˳�");
    getch();
}

/*�һ�����*/
void Find_Password(void) {
    Student *find_tem;
    char num_tem[50];
    printf("\t\t��ӭ�����һ�����ϵͳ\n");
    Sleep(500);
    printf("\t\t������\n");
    Sleep(500);
    int l = 1;
    while (l != 6) {
        printf("\t\t��������λ�˺ţ�");
        gets(num_tem);
        l = strlen(num_tem);
        if (l != 6)
            printf("\t\t�˺�������������ȷ���ȵ��˺�\n");
    }
    num_tem[6] = '\0';
    find_tem = Find_Num(num_tem);
    printf("\t\t��������˺ţ�");
    puts(num_tem);
    Sleep(500);
    printf("\t\t����Ϊ������\n");
    Sleep(500);
    printf("\t\t������\n");
    Sleep(500);
    if (find_tem == NULL) {
        printf("\t\t��Ǹ���޴��˺ţ������˳�ע��ϵͳ\n");
        Sleep(1000);
        printf("\t\t������\n");
        Sleep(1500);
        return;
    }
    printf("\t\t%s�����ã�\n", find_tem->stu_name);
    Sleep(300);
    printf("\t\t�����õ��ܱ������ǣ� %s\n", find_tem->stu_find_question);
    Sleep(300);
    printf("\t\t����������ܱ��������룺");
    if (Password_Text_Find(find_tem->stu_find_passw) == 0) {
        printf("\n\t\t�����������3�Σ����˳��һ�����ϵͳ������\n");
        Sleep(1500);
        return;
    }
    Sleep(500);
    printf("\n\t\t���ڲ���\n");
    Sleep(500);
    printf("\t\t������\n");
    Sleep(500);
    printf("\t\t������\n");
    Sleep(500);
    printf("\t\t%s ���ã����������� ��%s", find_tem->stu_name, find_tem->stu_passw);
    printf("\n\t\t���μ���������\n");
    printf("\t\t��������˳�");
    getch();


}

Student *Find_Num(char *Stu_num) {
    Student *t = Student_head->next;
    while (t) {
        if (strcmp(t->stu_acc, Stu_num) == 0)
            break;
        t = t->next;
    }
    return t;
}

/*ѧ���˵�¼*/
void Student_Login(void) {

    char sl = '1';
    char enter_num[50];
    int l = 1;

    Student *enter_stu;
    while (getchar() != '\n');  //��ջ�����
    while (l != 6) {
        printf("\n\t\t����������˺ţ�");
        gets(enter_num);
        l = strlen(enter_num);
        if (l != 6)
            printf("\t\t�˺�������������ȷ���ȵ��˺�\n");
    }
    enter_num[6] = '\0';
    enter_stu = Find_Num(enter_num);
    if (enter_stu == NULL) {
        printf("\n\t\t��Ǹ���޴��˺�");
        Sleep(500);
        printf("\n\t\t��������˳�");
        getch();
        return;
    }
    printf("\t\t���������룺");
    if (Password_Text_Find(enter_stu->stu_passw) == 0) {
        printf("\n\t\t�����������3�Σ����˳���¼ϵͳ������");
        Sleep(2000);
        return;
    }
    Sleep(500);
    printf("\n\t\t���ڵ�¼");
    Sleep(500);
    printf("\n\t\t������\n");
    Sleep(500);
    printf("\n\t\t��¼�ɹ���\n");
    Sleep(1000);


    while (sl != '0') {
        show_stu_enter();
        printf("\t\t��");
        scanf("%c", &sl);
        while (getchar() != '\n');  //��ջ�����
        switch (sl) {
            case '1':
                Stu_Borrow(enter_stu);              //����
                break;
            case '2':
                Stu_Back(enter_stu);                //����
                break;
            case '3':
                Find_Book();                                //�����鼮
                break;
            case '4':
                Find_Theborrow(enter_stu);          //���ҽ���
                break;
            case '5':
                studentNotice();                            //�鿴����
                break;
            case '6':
                Change_Stupassword(enter_stu);
                break;
            case '0':
                break;
            default:
                printf("\t\t�����������������\n");
                Sleep(1500);
                break;
        }
    }
}
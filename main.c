#include <stdio.h>
#include "Gui.h"
#include "DataManagement.h"
#include "StudentPort.h"
#include "ManagePage.h"
#include "NoticePort.h"

//������
int main(void) {
    //��ʼ������ͷ
    Book_head = (Book *) malloc(sizeof(Book));
    Student_head = (Student *) malloc(sizeof(Student));
    Manager_head = (Manager *) malloc(sizeof(Manager));
    Notice_head = (Notice *) malloc(sizeof(Notice));

    //��������
    Book_head->next = Book_load();
    Student_head->next = Student_load();
    Manager_head->next = Manager_load();
    Notice_head->next = Notice_load();

    //������
    char ma = '1';
    system("color F4"); //���ÿ���̨��ɫ
    while (ma != '0') {
        show_main();
        printf("\t\t\t��");
        scanf("%c", &ma);
        while (getchar() != '\n');
        switch (ma) {
            case '1':
                Student_Port();
                break;
            case '2':
                Manager_Port();
                break;
            case '0':
                Massage_Save();
                break;
            default:
                printf("\t\t�����������������\n");
                Sleep(3000);
                break;
        }
    }
    system("PAUSE");
    return 0;
}

#include <stdio.h>
#include "Gui.h"
#include "DataManagement.h"
#include "StudentPort.h"
#include "ManagePage.h"
#include "NoticePort.h"

//主函数
int main(void) {
    //初始化链表头
    Book_head = (Book *) malloc(sizeof(Book));
    Student_head = (Student *) malloc(sizeof(Student));
    Manager_head = (Manager *) malloc(sizeof(Manager));
    Notice_head = (Notice *) malloc(sizeof(Notice));

    //加载数据
    Book_head->next = Book_load();
    Student_head->next = Student_load();
    Manager_head->next = Manager_load();
    Notice_head->next = Notice_load();

    //主界面
    char ma = '1';
    system("color F4"); //设置控制台颜色
    while (ma != '0') {
        show_main();
        printf("\t\t\t：");
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
                printf("\t\t输入错误，请重新输入\n");
                Sleep(3000);
                break;
        }
    }
    system("PAUSE");
    return 0;
}

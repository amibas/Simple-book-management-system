#include <stdio.h>
#include "Gui.h"
#include "DataManagement.h"
#include "StudentPort.h"
#include "ManagePage.h"

int main(void) {
    Book_head = (Book *) malloc(sizeof(Book));
    Student_head = (Student *) malloc(sizeof(Student));
    Manager_head = (Manager *) malloc(sizeof(Manager));

    Book_head->next = Book_load();
    Student_head->next = Student_load();
    Manager_head->next = Manager_load();

    char ma = '1';

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

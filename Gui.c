//
// Created by amiba on 2023/4/2.
//

#include "Gui.h"

int mainMenu() {
    int functionSelection;
    system("mode con cols=54 lines=30");
    system("color F2");
    system("cls");
    printf("**********************************************\n");
    printf("*             ��ӭʹ��ͼ�����ϵͳ           *\n");
    printf("**********************************************\n");
    printf("\n");
    printf("*******************************\n");
    printf("   _____ ____  __  __  _____ \n"
           "  / ____|  _ \\|  \\/  |/ ____|\n"
           " | (___ | |_) | \\  / | (___  \n"
           "  \\___ \\|  _ <| |\\/| |\\___ \\ \n"
           "  ____) | |_) | |  | |____) |\n"
           " |_____/|____/|_|  |_|_____/ \n"
           "                            \n");
    printf("*******************************\n");
    printf("1. ��¼ 2.�˳�\n");
    printf("��ѡ���ܣ�");
    scanf("%d", &functionSelection);
    return functionSelection;
}

char loginMenu() {
    char userName[10];
    printf("�������˺�: ");
    scanf("%s", userName);
    login(userName);
}

int endMenu() {
    printf("\n");
    printf("************\n");
    printf("��л���ʹ��\n");
    printf("************\n");

    system("pause");
}

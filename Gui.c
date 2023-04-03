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
    printf("*             欢迎使用图书管理系统           *\n");
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
    printf("1. 登录 2.退出\n");
    printf("请选择功能：");
    scanf("%d", &functionSelection);
    return functionSelection;
}

char loginMenu() {
    char userName[10];
    printf("请输入账号: ");
    scanf("%s", userName);
    login(userName);
}

int endMenu() {
    printf("\n");
    printf("************\n");
    printf("感谢你的使用\n");
    printf("************\n");

    system("pause");
}

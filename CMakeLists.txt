cmake_minimum_required(VERSION 3.24)
project(Simple-book-management-system)

set(CMAKE_C_STANDARD 11)

add_executable(Simple-book-management-system main.c DataManagement.c Gui.c StudentPage.c StudentPort.c NotClassified.c ManagePage.c)

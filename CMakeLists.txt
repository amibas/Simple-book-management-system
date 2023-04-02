cmake_minimum_required(VERSION 3.24)
project(Simple-book-management-system)

set(CMAKE_C_STANDARD 11)

add_executable(main.c DataManagement.c DataManagement.h Gui.c Gui.h)

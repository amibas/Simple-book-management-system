//
// Created by amiba on 2023/4/2.
//

#ifndef SIMPLE_BOOK_MANAGEMENT_SYSTEM_FILETOOLS_H
#define SIMPLE_BOOK_MANAGEMENT_SYSTEM_FILETOOLS_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

extern FILE *fp;    //文件指针
extern char *fileName;

extern long getFileSize(FILE *fp);  //获取文件大小
extern long fcopy(FILE *fSource, long offsetSource, long len, FILE *fTarget, long offsetTarget);  //文件内容复制
extern int finsert(FILE *fp, char *fileName, long offset, void *buffer, int len);  //向文件中插入数据
extern int fdelete(FILE *fp, char *fileName, long offset, int len);  //删除文件内容
extern void pause(const char *str, ...);  //暂停程序

#endif //SIMPLE_BOOK_MANAGEMENT_SYSTEM_FILETOOLS_H

//
// Created by amiba on 2023/4/10.
//

#ifndef SIMPLE_BOOK_MANAGEMENT_SYSTEM_NOTICEPORT_H
#define SIMPLE_BOOK_MANAGEMENT_SYSTEM_NOTICEPORT_H

#include <stdio.h>
#include <synchapi.h>
#include "DataManagement.h"
#include "Gui.h"
#include "time.h"

extern void studentNotice();   //学生端公告页面

extern void View_Notice();      //查看公告

extern void Publish_Notice();   //发布公告

extern void Delete_Notice();    //删除公告

extern void findNotice();  //查找公告

#endif //SIMPLE_BOOK_MANAGEMENT_SYSTEM_NOTICEPORT_H

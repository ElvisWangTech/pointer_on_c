//
//  ch16_4.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2019/2/5.
//  Copyright © 2019 汪意伟. All rights reserved.
//

#include "ch16.h"

/**
 获取指定日期是星期几

 @param month 1-12
 @param day 1-31
 @param year 0-？距离1900年的年数
 */
void get_weekday(int month, int day, int year) {
    struct tm *tm;
    time_t now = time(0);
    tm = localtime(&now);
    tm->tm_mon = month - 1;
    tm->tm_mday = day;
    tm->tm_year = year;
    
    time_t time = mktime(tm);
    tm = localtime(&time);
    int weekday = tm->tm_wday;
    printf("%d/%d/%d是星期%d\n", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, weekday == 0 ? 7:weekday);
}

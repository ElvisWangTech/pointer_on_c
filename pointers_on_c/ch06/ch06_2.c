//
//  ch06_2.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/11/24.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#include "ch06.h"

int del_substr(char *str, char const *substr) {
    char *p = str;
    char *p1 = p;
    char const * psub = substr;
    int isFind = 0;
    char result[100];
    char *vp = &result[0];
    do {
        if (*p == *psub) {
            p1 = p;
            while (*psub++ != '\0' && *p1++ != '\0' && *p1 == *psub)
                ;
            if (*psub == '\0') {
                isFind = 1;
                break;
            }
        } else {
            *vp++ = *p;
        }
    } while( *p++ != '\0');
    // 找到，进行删除
    if (isFind) {
        while (*p1 != '\0') {
            // 这里b不能修改常量区*p的值, 所以我们创建一个result数组
            *vp++ = *p1++;
        }
        *vp = '\0';
        printf("new %s\n", result);
        return 1;
    }
    return 0;
}

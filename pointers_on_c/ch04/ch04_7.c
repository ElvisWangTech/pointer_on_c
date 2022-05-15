//
//  ch04_7.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/11/18.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#include "ch04.h"

void deblank(char string[]) {
    int i = 0, j = 0;
    char ch;
    int space_index = -1;
    // 获取数组的真实长度
    int len = 0;
    while (string[i++] != '\0') {
        len++;
    }
    i = 0;
    char new_string[len];
    while ((ch = string[i]) != '\0') {
        if (ch == ' ') {
            // 找到第一个空格 或者 当前的空格和上一个空格不是连续的
            if (space_index == -1 || space_index + 1 < i) {
                new_string[j++] = ' ';
            }
            space_index = i;
        } else {
            new_string[j++] = ch;
        }
        i++;
    }
    new_string[j++] = '\0';
//    printf("%s\n", new_string);
}

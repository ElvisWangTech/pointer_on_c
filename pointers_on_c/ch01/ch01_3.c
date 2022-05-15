//
//  ch01_3.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/11/4.
//  Copyright © 2018年 汪意伟. All rights reserved.
//
#include "ch01.h"
void print_checksum () {
    int ch;
    signed char checksum = -1;
    while((ch = getchar()) != EOF) {
        // 包含换行符
        checksum += ch;
         printf("%c", ch);
//        putchar(ch);
        if (ch == '\n') {
            break;
        }
    }
    printf("%d\n", checksum);
}

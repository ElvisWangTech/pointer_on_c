//
//  printWithEncodeAlpha.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/11/18.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#include <stdio.h>

void printWithEncodeAlpha() {
    char ch;
    while((ch = getchar()) != '\n') {
        if (ch >= 'A' && ch <= 'Z') {
            ch = ch + 13;
            ch = ch > 90? ch = ch - 90 + 64: ch;
        } else if (ch >= 'a' && ch <= 'z') {
            ch = ch + 13;
            ch = ch > 122? ch - 122 + 96: ch;
        }
        printf("%c", ch);
    }
    printf("\n");
}

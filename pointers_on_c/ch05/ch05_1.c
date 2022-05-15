//
//  ch05_1.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/11/18.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#include "ch05.h"

void printToLower () {
    char ch;
    while((ch = getchar()) != '\n') {
        if (ch >= 'A' && ch <= 'Z') {
            printf("%c", ch|0x20);
        } else {
            printf("%c", ch);
        }
    }
    printf("\n");
}

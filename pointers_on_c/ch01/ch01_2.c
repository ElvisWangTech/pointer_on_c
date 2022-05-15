//
//  ch01_2.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/10/28.
//  Copyright © 2018年 汪意伟. All rights reserved.
//

#include "ch01.h"

#define FALSE 0
#define TRUE 1

void print_with_lineno() {
    int ch, line=0, is_beginning = TRUE;
    while ((ch = getchar()) != EOF) {
        if(is_beginning) {
            is_beginning = FALSE;
            line+=1;
            printf("%d ", line);
        }
        
        putchar(ch);
        if(ch == '\n') {
            is_beginning = TRUE;
        }
    }
}

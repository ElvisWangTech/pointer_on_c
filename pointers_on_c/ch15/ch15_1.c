//
//  ch15_1.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2019/1/23.
//  Copyright © 2019 汪意伟. All rights reserved.
//

#include "ch15.h"

void print_std_char(void) {
    int ch;
    // print char until press ctrl+d
    while ((ch = getchar()) != EOF) {
        putchar(ch);
    }
}

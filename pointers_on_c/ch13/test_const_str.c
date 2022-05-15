//
//  test_const_str.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2019/1/9.
//  Copyright © 2019 汪意伟. All rights reserved.
//

#include "ch13.h"

void test_const_str(void) {
    
    printf("%s\n", ("xyz" + 1));
}

void mystery(int n) {
    n += 5;
    n /= 10;
    printf("%s\n", "**********" + 10 - n);
}

void int_to_hex(unsigned int value) {
    putchar("0123456789ABCDEF" [value % 16]);
}

//
//  ch09_5.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/12/23.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#include "ch09.h"

void my_strncat(char *dst, char const *src, size_t n, int dest_len) {
    assert((dst != NULL) && (src != NULL));
    char *r=dst;
    int len = 0, src_len = 0;
    while (*r++)
        len++;
    while((*r++ = *src++) != '\0' && len++ <= dest_len && src_len++ <= n)
        ;
    if (len > dest_len || src_len > n) {
        r--;
        *r = '\0';
    }
}

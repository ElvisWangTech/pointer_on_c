//
//  ch09_4.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/12/23.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#include "ch09.h"

char *my_strcat(char *dst, char const *src, int dest_len) {
    assert((dst != NULL) && (src != NULL));
    char *r=dst;
    int len = 0;
    while (*r++)
        len++;
    while((*r++ = *src++) != '\0' && len++ <= dest_len)
        ;
    if (len > dest_len) {
        r--;
        *r = '\0';
    }
    return dst;
}

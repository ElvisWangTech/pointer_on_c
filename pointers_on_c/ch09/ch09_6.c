//
//  ch09_6.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/12/23.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#include "ch09.h"

char *my_strcpy_end(char *dst, const char *src) {
    assert((dst != NULL) && (src != NULL));
    int len = 0;
    while((*dst++ = *src++) != '\0')
        ;
    return dst--;
}

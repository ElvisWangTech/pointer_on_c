//
//  ch06_1.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/11/24.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#include "ch06.h"

char *find_char(char const *source, char const *chars) {
    char const * p1, *p2;
    p1 = source;
    p2 = chars;
    while(*p1++ != '\0') {
        while (*p2++ != '\0') {
            if(*p1 == *p2) {
                return p1;
            }
        }
    }
    return NULL;
}

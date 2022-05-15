//
//  ch09_8.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/12/23.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#include "ch09.h"

char *my_strnchr(char const *str, int ch, int which) {
    char *ptr;
    int i;
    for (ptr = str, i = 0; i < which; i++) {
        ptr = strchr(ptr, ch);
    }
    return ptr;
}

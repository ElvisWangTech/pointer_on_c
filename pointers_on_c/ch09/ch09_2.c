//
//  ch09_02.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/12/23.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#include "ch09.h"

size_t my_strlen(char const *string, int max_len) {
    int len;
    for (len = 0; *string++ != '\0' && len <= max_len; ) {
        len++;
    }
    return len;
}

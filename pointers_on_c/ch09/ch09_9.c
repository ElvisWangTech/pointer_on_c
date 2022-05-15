//
//  ch09_9.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/12/23.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#include "ch09.h"

int count_chars(char const *str, char const *chars) {
    int count;
    char *ptr = str;
    while((ptr = strpbrk(ptr, chars)) != NULL) {
        count++;
    }
    return count;
}

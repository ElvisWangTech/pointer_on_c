//
//  ch09_7.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/12/23.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#include "ch09.h"

char *my_strrchr(char const *str, int ch) {
    char *p = strrchr(str, ch);
    return p;
}

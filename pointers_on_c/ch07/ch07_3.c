//
//  ch07_3.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/12/1.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#include "ch07.h"

int ascii_to_integer(char *string) {
    char *p = string;
    char ch;
    int result = 0;
    while ( (ch = *p++) != '\0') {
        if (ch < '0' || ch > '9')
            return 0;
        
        if (result == 0) {
            result = (ch  - '0');
        } else {
            result *= 10;
            result += (ch - '0');
        }
    }
    return result;
}

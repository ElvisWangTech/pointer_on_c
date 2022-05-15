//
//  ch09_15.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/12/31.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#include "ch09.h"

void dollars(char *dest, char const *src) {
    int len = strlen(src);
    char *p = dest;
    *p++ = '$';
    // len < 5时需要特殊处理
    if(len == 0) {
        *p++ = '0';
        *p++ = '.';
        *p++ = '0';
        *p++ = '0';
    } else if(len == 1) {
        *p++ = '0';
        *p++ = '.';
        *p++ = '0';
        *p++ = *src;
    } else if (len == 2) {
        *p++ = '0';
        *p++ = '.';
        *p++ = *(src);
        *p++ = *(src+1);
    } else if (len == 3) {
        *p++ = *src;
        *p++ = '.';
        *p++ = *(src+1);
        *p++ = *(src+2);
    } else if (len == 4) {
        *p++ = *src;
        *p++ = *(src+1);
        *p++ = '.';
        *p++ = *(src+2);
        *p++ = *(src+3);
    }
    // len > 5才会出现逗号
    else {
        // 第一个逗号的出现的位置
        int first_comma_loc = (len - 2) % 3;
        for (int i = 0; *(src + i) != '\0'; i++) {
            if (i == first_comma_loc && first_comma_loc != 0) {
                *p++ = ',';
            }
            // 每隔3个加一个逗号
            else if (i > first_comma_loc && i + 2 < len && (i - first_comma_loc) % 3 == 0) {
                *p++ = ',';
            }
            // 添加小数点
            else if (i + 2 == len) {
                *p++ = '.';
            }
            *p++ = *(src + i);
        }
    }
    
    *p++ = '\0';
    printf("%s \n", dest);
}

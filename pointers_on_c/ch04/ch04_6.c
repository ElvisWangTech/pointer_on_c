//
//  ch04_6.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/11/18.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#include "ch04.h"

int substr(char dst[], char src[], int start, int len) {
    int count = 0;
    if (start >= 0 && len >= 0) {
        for (int i = start; i < len; i++) {
//            printf("%c", src[i]);
            if (src[i] != '\0') {
                dst[i] = src[i];
                count++;
            } else {
                break;
            }
        }
    }
    dst[count] = '\0';
    return count;
}

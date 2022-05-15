//
//  ch06_3.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/11/24.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#include "ch06.h"

void reverse_string(char *string) {
    // 定位末尾
    char * ps = string;
    while(*ps++ != '\0')
        ;
    while(ps-- != string) {
        printf("%c", *ps);
    }
    printf("\n");
}

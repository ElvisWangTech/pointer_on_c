//
//  ch02.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/11/4.
//  Copyright © 2018年 汪意伟. All rights reserved.
//

#include "ch02.h"

void check_valid_c(const char *path) {
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        printf("file open error: %s", path);
        exit(1);
    }
    int ch, pair = 0;
    while((ch = fgetc(fp)) != EOF) {
        if (ch == '{') {
            pair++;
        } else if (ch == '}') {
            pair--;
        }
    }
    if(pair == 0) {
        printf("file %s is valid!!", path);
    } else {
        printf("file %s is not valid!!", path);
    }
}

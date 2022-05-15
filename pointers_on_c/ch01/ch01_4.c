//
//  ch01_4.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/11/4.
//  Copyright © 2018年 汪意伟. All rights reserved.
//

#include "ch01.h"

#define MAX_CH_SI 1000

void print_longest_line(const char *path) {
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        printf("file open error: %s", path);
        exit(EXIT_FAILURE);
    }
    char line[MAX_CH_SI], max_line[MAX_CH_SI];
    int len = 0, max_len = 0;
//    while (!feof(fp)) {
//        memset(line, 0, sizeof(line));
//        fgets(line, sizeof(line) - 1, fp);
//        len = strlen(line);
//        if (len > max_len) {
//            max_len = len;
//            strncpy(max_line, line, max_len);
//        }
//    }
    
    while ((fgets(line, sizeof(line) - 1, fp)) != NULL) {
        len = strlen(line);
        if (len > max_len) {
            max_len = len;
            strncpy(max_line, line, max_len);
        }
    }
    printf("Logest line is : %s",  max_line);
    
    fclose(fp);
}

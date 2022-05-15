//
//  ch04_4.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/11/18.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#include "ch04.h"

void copy_n(char dst[], char src[], int n) {
    // 判断目标数组是否够n个长度
//    int dst_len = sizeof(dst)/sizeof(char);
//    if (dst_len < n) {
//        printf("{%d} 目标数据的存储空间不够\n", dst_len);
//        return;
//    }
    printf("old dst: %s\n", dst);
    // 初始化目标数组
    for (int i = 0; i < n; i++) {
        dst[i] = '\0';
    }
    // 复制数据
//    int src_len = sizeof(src)/sizeof(char);
    int src_end = 0;
    for (int j = 0; j < n; j++) {
        if (src_end) {
            dst[j] = '\0';
        } else if (src[j] == '\0') {
            src_end = 1;
        } else {
            dst[j] = src[j];
        }
    }
    printf("src: %s\n", src);
    printf("new dst: %s\n", dst);
}

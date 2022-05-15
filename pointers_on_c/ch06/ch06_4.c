//
//  ch06_4.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/12/1.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#include "ch06.h"

int getStep(int flags[], int len, int step) {
    while(flags[++step] == 0 && step < len)
        ;
    if (flags[step] != 0) {
        return step;
    } else {
        return 0;
    }
}

void eratosthenes(int max) {
    if (max < 2) return;
    // 创建标记数组
    int len = max+1;
    int flags[len];
    for (int i = 2; i <= max; i++) {
        flags[i] = 1;
    }
    // 循环判断
    int step = 1;
    while ((step = getStep(flags, len, step)) != 0) {
//        printf("new step %d \n", step );
        int index = step + step;
        for (; index <= max; index += step) {
//            printf("%d is not prime!\n", index);
            flags[index] = 0;
        }
    }
    // 打印质数
    for (int i = 2; i < max; i++) {
        if (flags[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
    
}

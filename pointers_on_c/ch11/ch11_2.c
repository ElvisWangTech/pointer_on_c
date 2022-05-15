//
//  ch11_2.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2019/1/7.
//  Copyright © 2019 汪意伟. All rights reserved.
//

#include "ch11.h"

int *gen_ints(void) {
    int i,j = 0,len = 0;
    int *arr = NULL;
    while (scanf("%d", &i) != EOF) {
        // 第一个数表示元素的个数
        if (arr == NULL) {
            arr = calloc(i, i * sizeof(int));
            if (arr == NULL) {
                printf("alloc memory error. ");
                return NULL;
            }
            len = i;
        } else {
            // 超出了数组最大长度
            if (j >= len) {
                // break;
                arr = realloc(arr, (len+1) * sizeof(int));
                if (arr == NULL) {
                    printf("alloc memory error. ");
                    return NULL;
                }
                
            }
            arr[j++] = i;
        }
    }
    for (int k = 0; k < len; k++) {
        printf("%d ", arr[k]);
    }
    return arr;
}

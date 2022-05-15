//
//  ch13_4.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2019/1/16.
//  Copyright © 2019 汪意伟. All rights reserved.
//

#include "ch13.h"

/*
 简单选择排序， 每次循环都选择一个最小的数
 p_first_el: 指向数组的第一个元素的指针
 arr_size: 数组大小
 el_size: 数组元素的长度 sizeof
 comparator: 数组元素比较器
 */
void sort_array(void *p_first_el, int arr_size, int el_width, int (*comparator)(void const *, void const *)) {
    int i, j;
    char *loc = (char *)p_first_el;
    char *low, *hig;
    for (i = 0; i < arr_size - 1; i++) {
        for (j = i + 1; j < arr_size; j++) {
            // 如果元素i>元素j，交换i，j
            low = loc + i * el_width;
            hig = loc + j * el_width;
            if (comparator(low, hig) > 0) {
                void *p = malloc(el_width);
                assert(p != NULL);
                memcpy(p, hig, el_width);
                memcpy(hig, low, el_width);
                memcpy(low, p, el_width);
                free(p);
            }
        }
    }
}

/*
 比较两个字符大小
 */
int compare_char(const void *ch0, const void *ch1) {
    char *a = (char *)ch0;
    char *b = (char *)ch1;
    int c = *a - *b;
    return c;
}

/*
 比较两个浮点数大小
 */
int compare_float(const void *f0, const void *f1) {
    return *(float *)f0 - *(float *)f1;
}


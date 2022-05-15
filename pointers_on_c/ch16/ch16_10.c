//
//  ch16_10.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2019/2/5.
//  Copyright © 2019 汪意伟. All rights reserved.
//

#include "ch16.h"

/**
 实现插入排序

 @param base <#base description#>
 @param n_elements <#n_elements description#>
 @param el_size <#el_size description#>
 @param compare <#compare description#>
 */
void insert_sort(void *base, size_t n_elements, size_t el_size,
                 int (*compare)(void const *, void const *)) {
    int i, j;
    char *loc = (char *)base;
    char *low, *hig;
    
    for (i = 1; i < n_elements; i++) {
        j = i;
        low = loc + (j - 1) * el_size;
        hig = loc + j * el_size;
        while (j > 0 && compare(low, hig) > 0) {
            void *p = malloc(el_size);
            memcpy(p, hig, el_size);
            memcpy(hig, low, el_size);
            memcpy(low, p, el_size);
            free(p);
            j--;
            low = loc + (j - 1) * el_size;
            hig = loc + j * el_size;
        }
    }
}

//
//  ch11_1.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2019/1/7.
//  Copyright © 2019 汪意伟. All rights reserved.
//

#include "ch11.h"

void test_myalloc(void) {
    myalloc(2, sizeof(int), int);
}

void *mycalloc2(size_t num_elements, size_t element_size) {
    int i;
    num_elements = num_elements * element_size;
    char *p = malloc(num_elements);
    if(p == NULL)
        return NULL;
    for(i = 0; i < num_elements; i++)
        p[i] = 0;
    return p;
}

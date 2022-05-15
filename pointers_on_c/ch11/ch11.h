//
//  ch11.h
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/12/23.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#ifndef ch11_h
#define ch11_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 分配并返回内存大小 */
//#define malloc_t(num, T) \
//malloc_usable_size(malloc(num * sizeof(T)))

/* 用malloc实现的calloc方法， calloc带初始化和返回值检测 */
void *mycalloc2(size_t num_elements, size_t element_size);

#define  myalloc(num_elements, element_size, element_type)          \
do {                                                                \
    element_type *p=malloc(element_size * num_elements);            \
    if (p == NULL)  {                                               \
         exit(0);                                                   \
    }                                                               \
    for (int i = 0; i < num_elements; i++) {                        \
        p[i] = 0;                                                   \
    }                                                               \
    printf("alloc ok!");                                            \
} while(0)

/* 测试myalloc */
void test_myalloc(void);

/* 从标准输入获取动态分配的整型数组 */
int *gen_ints(void);

/* 从标准输入读取字符串并返回字符串的拷贝 */
char *read_str_dup(void);

/* 创建一个简单的链表，并动态分配内存 */
typedef struct NODE {
    int value;
    struct NODE * next;
} Node;

Node *gen_nodes(void);

#endif /* ch11_h */

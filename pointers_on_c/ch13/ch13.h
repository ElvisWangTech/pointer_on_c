//
//  ch13.h
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/13/23.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#ifndef ch13_h
#define ch13_h

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include "ch12.h"

void test_const_str(void);

/* 神秘函数 */
void mystery(int n);

/* 把二进制转换为字符的新方法 */
void int_to_hex(unsigned int value);

/* 从标准输入读取字符，统计各类字符所占的百分比 */
void count_char_type_new(void);

/* 编写通用函数，遍历单链表，并指定一个回调函数 */
void find_node_with_callback(Node *first, void (*func)(Node *));

/* 编写通用的函数，可以传入指定的比较器对任何类型的数组进行排序 */
void sort_array(void *p_first_el, int arr_size, int el_size, int (*comparator)(void const *, void const *));

/* 字符数组比较器 */
int compare_char(const void *, const void *);

/* 浮点数比较器 */
int compare_float(const void *, const void *);

/* 处理命令行参数，要求按control的规则处理参数 ch13_5.c */
char ** do_args(int argc, char **argv, char *control,
                void (*do_arg) ( int ch, char *value ),
                void (*illegal_arg) ( int ch ));

/* 参数处理方法 */
void handle_arg(int ch, char *value);

/* 非法参数处理方法 */
void handle_illegal_arg(int ch);
#endif /* ch13_h */

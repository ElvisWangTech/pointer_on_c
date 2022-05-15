//
//  ch07.h
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/11/10.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#ifndef ch07_h
#define ch07_h

#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>

// 计算厄密多项式的值--递归方法
int hermite(int n, int x);

// 计算厄密多项式的值--迭代法
int hermite2(int n, int x);

// 计算最大公约数
int gcd(int m, int n);

// 将字符串转换为整数并输出, 画不考虑算术溢出
int ascii_to_integer(char *string);

// 找出最大数,参数不限
int max_list(int, ...);

#endif /* ch07_h */

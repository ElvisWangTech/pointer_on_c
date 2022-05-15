//
//  ch06.h
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/11/10.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#ifndef ch06_h
#define ch06_h

#include <stdio.h>
#include <stdbool.h>

// 查找指定的字符
char *find_char(char const *source, char const *chars);
// 删除字符串的一部分
int del_substr(char *str, char const *substr);
// 字符串反向排列
void reverse_string(char *string);
// Eratosthenes筛选法求2-max内所有的质数
void eratosthenes(int max);
// Eratosthenes筛选法求2-max内所有的质数 -- 版本2
// v2版本实现了空间优化
void eratosthenes_v2(int max);

#endif /* ch06_h */

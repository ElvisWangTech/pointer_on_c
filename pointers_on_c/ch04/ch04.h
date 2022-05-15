//
//  ch04.h
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/11/10.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#ifndef ch04_h
#define ch04_h

#include <stdio.h>
// 计算平方根
float getSquareRoot(int n);

// 打印1-100间所有的质数
void printPrime(int start, int end);

// 判断三角形类型
void checkTriangle(float a, float b, float c);

// 实现数组元素复制
void copy_n(char dst[], char src[], int n);

// 打印相邻行重复的字符串
void printDupLine(const char * path);

// 提取子字符串
int substr(char dst[], char src[], int start, int len);

// 去除字符串中多余的空格
void deblank(char string[]);

#define BUFFER_SIZE 128

#endif /* ch04_h */

//
//  ch08.h
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/11/10.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#ifndef ch08_h
#define ch08_h

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

// 测试回文。8.7.4
int test_palindrome(char []);
// 测试回文,指针改写。8.7.4
int test_palindrome_v2(char []);
// 声明多维数组
void def_char_value(void);
// 计算个人所得税
float single_tax(float income);
//判断是否为单位矩阵
int identity_matrix(int[][10]);
//判断任意大小矩阵是否是单位矩阵
int identity_matrix_n(int *, int);
//打印矩阵
void print_matrix(int *matrix, int row, int col);
//矩阵相乘
void matrix_multiply(int *m1, int *m2, int *r, int x, int y, int z);
// 八皇后问题求解
void test_eight_queens(void);
// 访问伪数组
int array_offset(int arrayinfo[], ...);

#endif /* ch08_h */

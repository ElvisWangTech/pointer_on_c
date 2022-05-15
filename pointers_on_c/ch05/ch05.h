//
//  ch05.h
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/11/10.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#ifndef ch05_h
#define ch05_h

#include <stdio.h>
#include <limits.h>

// 转换标准输入，将大写字母转换成小写字母
void printToLower(void);
// 加密字母并打印
void printWithEncodeAlpha(void);
// 转置bit位
unsigned int my_reverse_bits(unsigned int value);
unsigned int reverse_bits(unsigned int value);
// 位函数
void set_bit(char bit_array[], unsigned bit_number);
void clear_bit(char bit_array[], unsigned bit_number);
void assign_bit(char bit_array[], unsigned bit_number, int value);
int test_bit(char bit_array[], unsigned bit_number);
// 将给定的值存储到一个整数指定的位
int store_bit_field(int original_value, int value_to_store, unsigned starting_bit, unsigned ending_bit);
#endif /* ch05_h */

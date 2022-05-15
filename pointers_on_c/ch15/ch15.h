//
//  ch15.h
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/13/23.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#ifndef ch15_h
#define ch15_h

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <setjmp.h>
#include <signal.h>

#include "ch09.h"
#include "ch04.h"

/* 测试prinf相关 */
void test_print(void);
/* 把标准输入的字符复制到标准输出 */
void print_std_char(void);

#define MAX_SIZE 8
/* 把标准输入的字符整行复制到标准输出 gets */
void print_std_line(void);
/* 把标准输入的字符整行复制到标准输出 fgets */
void print_std_line2(void);

/* 从标准输入读入两个文件名，一个为输入文件，一个为输出文件，将输入文件的内容复制到输出文件 */
int copy_file(const char *fileinput, const char *fileoutput);

/* 改写4的程序，统计整数并求和 */
int fetch_integers(const char *fileinput, const char *fileoutput);
/* 判断整型变量的值是否是回文 */
int numeric_palidrome( int value );

/* 统计家庭成员的平均年龄 */
void count_avg_age(const char *fileinput);

/* 最大字节数目 */
#define MAX_COUNT 16

/* 产生一个文件的16进制倾印码 */
void print_dump(const char *fileinput);

#undef BUFFER_SIZE
#define BUFFER_SIZE 512
/* 实现fgrep命令 */
void fgrep(int argc, const char * argv[]);

/* 计算文件校验和 */
int sum(int argc, const char * argv[]);

/* 零件存货记录 */
void parts_mgr(int argc, const char * argv[]);

#endif /* ch15_h */

//
//  ch16.h
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/13/23.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#ifndef ch16_h
#define ch16_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <setjmp.h>
#include <signal.h>
#include <string.h>
#include <math.h>

#include "ch13.h"

/* 问题 */
void test_questions(void);

/* 计算数值a字面值小于等于29的最小基数（2-36） */
void get_min_base(void);

/* 模拟掷骰子 */
int get_rand_num(int s_range, int e_range);

/* 编写一个程序，以三岁小孩的口吻来说明当前时间 */
void speek_time_baby(void);

/* 计算特定日期是星期几 */
void get_weekday(int month, int day, int year);

/* 计算风寒度 */
double wind_chill(double temp, double velocity);

/* 计算月支付贷款 */
double payment(double amount, double interest, int years);

/* 测试随机数生成函数 */
void test_rand_func(void);

/* 统计家庭成员的平均年龄 */
void count_avg_age_new(const char *fileinput);

/* 计算生日是同一天的概率 */
void check_birth(int person_num);

/* 实现插入排序 */
void insert_sort(void *base, size_t n_elements, size_t el_size,
                 int (*compare)(void const *, void const *));

#endif /* ch16_h */

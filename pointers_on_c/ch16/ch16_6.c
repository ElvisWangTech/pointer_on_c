//
//  ch16_6.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2019/2/5.
//  Copyright © 2019 汪意伟. All rights reserved.
//

#include "ch16.h"

/**
 计算月付贷款

 @param amount 贷款数量
 @param interest 年利率 12% = 0.12
 @param years 贷款年限
 @return 贷款的月付金额，精确到美分
 */
double payment(double amount, double interest, int years) {
    // 计算每个时段的利率
    double interest_stage = interest / 12;
    double payment;
    // 贷款需要的时段数
    int num_stage = years * 12;
    double div_a = amount * interest_stage;
    double div_b = 1 - pow(1 + interest_stage, -num_stage);
    payment = div_a / div_b;
    return payment;
}

//
//  ch10.h
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/12/23.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#ifndef ch10_h
#define ch10_h

#include <stdio.h>

struct NODE {
    int a;
    struct NODE *b;
    struct NODE *c;
};

/* 问题7， 根据node相关声明写出各个表达式的值 */
void print_nodes(void);

/* 手机号码信息 */
struct Tel {
    char *area_code; // 区号
    char *exchanger; // 交换台
    char *station_code; // 站号码
};
/* 记录长途电话的记账信息 */
struct Callbill {
    long long date;
    struct Tel *belong; // 使用的号码
    struct Tel *callto; // 被呼叫段号码
    struct Tel *forpay; // 付账的号码
};

/* 汽车销售i记录 */
struct CAR_SALE_REC {
    char customer_name[21]; // 顾客姓名
    char customer_address[41]; // 顾客地址
    char model[21]; // 模型
    enum {PURE_CASH, CASH_LOAN, LEASE} type;  // 交易类型
    float sale_price; // 实际售出价格
    float msrp; // 生产厂家建议零售价
    union {
        struct {
            float sale_tax; // 营业税
            float license_fee; // 许可费用
        } pure_cash;
        struct {
            float sale_tax; // 营业税
            float license_fee; // 许可费用
            float doun_payment; // 预付定金
            int loan_duration; // 贷款期限
            float interest_rate; // 贷款利率
            float monthy_payment; // 月付金额
            char bank[21]; // 银行名称
        } cash_loan;
        struct {
            float doun_payment; // 预付定金
            float security_deposit; // 安全抵押
            float monthy_payment; // 月付金额
            int lease_term; // 租赁期限
        } lease;
    };
};

/* 声明指令解码器 */
typedef union {
    unsigned short addr;
    // 单操作数指令
    struct {
        unsigned opcode: 10;
        unsigned dst_reg: 3;
        unsigned dst_mode: 3;
    } sgl_op;
    // 双操作数指令
    struct {
        unsigned opcode: 4;
        unsigned dst_reg: 3;
        unsigned dst_mode: 3;
        unsigned src_reg: 3;
        unsigned src_mode: 3;
    } dbl_op;
    // 转移指令
    struct {
        unsigned opcode: 8;
        unsigned offset: 8;
    } branch;
    // 源寄存器指令
    struct {
        unsigned dst_reg: 3;
        unsigned dst_mode: 3;
        unsigned src_reg: 3;
        unsigned opcode: 7;
    } reg_src;
    // 其余指令
    struct {
        unsigned opcode: 16;
    } misc;
} machine_inst;


#endif /* ch10_h */

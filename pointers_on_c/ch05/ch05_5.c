//
//  ch05_5.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/11/18.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#include "ch05.h"

int store_bit_field(int original_value, int value_to_store, unsigned starting_bit, unsigned ending_bit) {
    // step1 创建掩码
    unsigned mask = 1;
    int num = starting_bit - ending_bit;
    while(num--) {
        mask <<= 1;
        mask |= 1;
    }
    mask <<= ending_bit;
//    printf("mask: %x\n", mask);
    // step 2 用原码的反码和原值进行AND操作
    int unmask = ~mask;
    int original_value_unmask = original_value &= unmask;
//    printf("step 2 : %x\n", original_value);
    // step 3 将新值左移
//    printf("step 3 value_to_store: %x\n", value_to_store);
    int value_withoff = value_to_store << ending_bit;
//    printf("step 3 : %x\n", value_withoff);
    // step 4 和掩码进行AND操作
    int result_value = mask & value_withoff;
//    printf("step 4 : %x\n", result_value);
    // step 5 和原值进行OR操作
    result_value |= original_value_unmask;
    return result_value;
}

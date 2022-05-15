//
//  ch05_3.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/11/18.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#include "ch05.h"

/*
 * 参考答案
 */
unsigned int reverse_bits(unsigned int value) {
    unsigned int answer;
    unsigned int i;
    
    answer = 0;
    
    for (i = 1; i != 0; i <<= 1) {
        answer <<= 1;
        if (value & 1) {
            answer |= 1;
        }
        value >>= 1;
    }
    return answer;
}

/*
 * 另外一个实现版本
 */
unsigned int my_reverse_bits(unsigned int value) {
    int bit_index = 0;
    int mask;
    int sum = 0;
    int bit_len = sizeof(unsigned int) * 8;
    unsigned int value_on_bit = 0;
    while(bit_index < bit_len) {
        mask = 1 << bit_index;
//        sum += (mask & value) << (bit_len - bit_index - 1);
        value_on_bit = ( mask & value );
//        printf("value on bit: %u bit_index: %d\n", value_on_bit, bit_index);
        if (value_on_bit > 0) {
            value_on_bit = value_on_bit << (bit_len - bit_index * 2 - 1);
//            printf("left move %d bit, new value is %u\n", bit_len - bit_index * 2 - 1, value_on_bit);
        }
        sum += value_on_bit;
        bit_index++;
    }
//    printf("sum is %u\n", sum);
    return sum;
}

//
//  ch06_4_v2.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/12/1.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#include "ch06.h"
#include "ch05.h"

void eratosthenes_v2(int max) {
    if (max < 2) return;
    
    // 处理首尾是偶数的情况
    if (max%2==0) {
        max = max-1;
    }
    // 创建标记数组(只存奇数)
    int len = (max)/CHAR_BIT+1;
    char bit_flags[len];
    for (int i=0; i<max; i++) {
        set_bit(bit_flags, i);
    }
    // 循环判断，每次循环都找到第一个没被踢除的数，然后将列表后面所有和这个数的倍数的数剔除（bit位置0）
    int start = 2, follow;
    while (test_bit(bit_flags, start) && start < max) {
        follow = start;
        while ((follow += start) < max) {
            clear_bit(bit_flags, follow);
        }
        while (!test_bit(bit_flags, ++start))
            ;
    }
    // 打印质数
    int sum = 0;
    for (int i = 2; i < max; i++) {
        if (test_bit(bit_flags, i)) {
             printf("%d ", i);
            sum++;
        }
    }
    printf("\n%d-%d: %d\n", 2, max, sum);
}

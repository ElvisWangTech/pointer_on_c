//
//  ch16_2.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2019/2/1.
//  Copyright © 2019 汪意伟. All rights reserved.
//

#include "ch16.h"

static int first = 1;

int get_rand_num(int s_range, int e_range) {
    // 初始化随机数生成器
    if (first) {
        srand((unsigned int)time(NULL));
        first = 0;
    }
    
    int range = e_range - s_range + 1;
    return s_range + rand() % range;
}

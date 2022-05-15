//
//  ch16_9.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2019/2/5.
//  Copyright © 2019 汪意伟. All rights reserved.
//

#include "ch16.h"

#define TEST_CNT 10000

void check_birth(int person_num) {
    int persons[person_num];
    srand((unsigned int)time(NULL));
    int i, j, k;
    int pool[365];
    // 命中数
    int hits = 0;
    // 重复10000次
    for (k = 0; k < TEST_CNT; k++) {
        // 初始化
        memset(pool, 0, sizeof(int) * 365);
        for (i = 0; i < person_num; i++) {
            j = rand() % 365;
            persons[i] = j;
            pool[j] += 1;
            // 包含有同一天生日的情况
            if (pool[j] > 1) {
                hits++;
                break;
            }
        }
    }
    
    printf("%d 人中生日相同的概率为%.2lf\n", person_num, (double)hits / TEST_CNT);
}

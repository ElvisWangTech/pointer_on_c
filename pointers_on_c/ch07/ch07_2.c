//
//  ch07_2.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/12/1.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#include "ch07.h"


/*
 大数m和小数n取模运算，如果结果r为0，则n为最大公约数,
 否则计算m%r，直到结果r为0
 */
int gcd(int m, int n) {
    
    int r = m%n;
    if (r == 0) {
        return n;
    }
    return gcd(m, r);
}

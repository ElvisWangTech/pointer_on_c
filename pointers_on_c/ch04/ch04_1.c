//
//  ch04_1.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/11/18.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#include "ch04.h"

float getSquareRoot(int n) {
    int i = 1;
    float a1 = 1.0;
    float a2 =(a1 + n/a1) / 2;
    while (a1 != a2) {
        i++;
        a1 = a2;
        a2 = (a1 + n/a1) / 2;
    }
    printf("计算了%d次\n", i);
    return a2;
}

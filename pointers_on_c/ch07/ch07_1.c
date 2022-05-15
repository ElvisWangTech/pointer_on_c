//
//  ch07_1.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/12/1.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#include "ch07.h"

int hermite(int n, int x) {
    if (n <= 0) {
        return 1;
    } else if (n == 1) {
        return 2 * x;
    } else {
        return 2 * x * hermite(n - 1, x) - 2 * (n-1) * hermite(n - 2, x);
    }
}

int hermite2(int n, int x) {
    int preval, prepreval, result;
    result = prepreval = 1;
    preval = 2;
    if (n == 1) {
        result = 2;
    }
    while (n >= 2) {
        result = preval * x * 2 - prepreval * (n-1) * 2;
        prepreval = preval;
        preval = result;
        n--;
    }
    return result;
}

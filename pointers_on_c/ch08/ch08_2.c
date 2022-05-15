//
//  ch08_2.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/12/8.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#include "ch08.h"

float single_tax(float income) {
    assert(income >= 0);
    float tax_rate[] = {0.15, 0.28, 0.31, 0.36, 0.396};
    float tax_distance[] = {0.0, 3502.50, 12798.50, 31832.50, 81710.50};
    float tax_baseline[] = {0.0, 23350, 56550, 117950, 256500};
    
    float tax = 0;
    int len = sizeof(tax_baseline) / sizeof(tax_baseline[0]);
    int i = 0;
    for (; i < len; i++) {
        if (income <= tax_baseline[i])
            break;
    }
    i = i==0?0:(i-1);
    tax = (income - tax_baseline[i]) * tax_rate[i] + tax_distance[i];
    return tax;
}

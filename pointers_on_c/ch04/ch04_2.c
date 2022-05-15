//
//  ch04_2.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/11/18.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#include "ch04.h"

void printPrime(int start, int end) {
    int i,j,flag;
    for (i = start; i <= end; i++) {
        if (i < 2) continue;
        j = i/2;
        flag=1;
        while (j > 1) {
            if(i % j == 0) {
                flag=0;
                break;
            }
            j--;
        }
        if (flag) {
            printf("%d ", i);
        }
    }
}

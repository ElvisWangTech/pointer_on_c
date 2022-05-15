//
//  ch08_4.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/12/8.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#include "ch08.h"

int identity_matrix_n(int *matrix, int n) {
    int i,j;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            // i==j表达式为1或者为0，为1时在对角线上，因为数组的内存上连续的，所以多维数组可以当作一维数组遍历，下标只要还在数组内存空间内就是合法的
            if(*matrix++ != (i == j))
                return 0;
        }
    }
    return 1;
}

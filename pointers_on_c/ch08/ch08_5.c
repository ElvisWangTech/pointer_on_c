//
//  ch08_5.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/12/8.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#include "ch08.h"

void print_matrix(int *matrix, int row, int col) {
    int i,j;
    printf("\n--------------------------\n");
    for(i=0; i<row; i++) {
        for (j=0; j<col; j++) {
            printf("%d\t", *matrix++);
        }
        printf("\n");
    }
    printf("--------------------------\n");
}
/*
 x:3 y:2 z:4
 r0 = *(m1+0) * (*(m2+0)) + *(m1+1) * (*(m2+4))
 r1 = *(m1+0) * (*(m2+1)) + *(m1+1) * (*(m2+4+1))
 r2 = *(m1+0) * (*(m2+2)) + *(m1+1) * (*(m2+4+2))
 r3 = *(m1+0) * (*(m2+3)) + *(m1+1) * (*(m2+4+3))
 
 r4 = *(m1+2+0) * (*(m2+0)) + *(m1+2+1) * (*(m2+4))
 r5 = *(m1+2+0) * (*(m2+1)) + *(m1+2+1) * (*(m2+4+1))
 r6 = *(m1+2+0) * (*(m2+2)) + *(m1+2+1) * (*(m2+4+2))
 r7 = *(m1+2+0) * (*(m2+3)) + *(m1+2+1) * (*(m2+4+3))
 
 r8 = *(m1+4+0) * (*(m2+0)) + *(m1+4+1) * (*(m2+4))
 r9 = *(m1+4+0) * (*(m2+1)) + *(m1+4+1) * (*(m2+4+1))
 r10 = *(m1+4+0) * (*(m2+2)) + *(m1+4+1) * (*(m2+4+2))
 r12 = *(m1+4+0) * (*(m2+3)) + *(m1+4+1) * (*(m2+4+3))
 */
void matrix_multiply(int *m1, int *m2, int *r, int x, int y, int z) {
    int i, j, m;
    int p, q;
    int *pi = r;
    for (i = 0; i + y <= x * y; i += y) {
        for (j = 0; j < z; j++) {
            *pi = 0;
            for (m = 0; m < y; m++) {
                p = *(m1 + i + m);
                q = *(m2 + z * m + j);
                *pi +=  p * q;
            }
            pi++;
        }
    }
}

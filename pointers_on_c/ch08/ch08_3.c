//
//  ch08_3.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/12/8.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#include "ch08.h"

int identity_matrix(int matrix[10][10]) {
    int i,j;
    for(i=0; i<10; i++) {
        for(j=0; j<10; j++) {
            if ((i==j && matrix[i][j] != 1) || (i!=j && matrix[i][j] != 0)) {
                return 0;
            }
        }
    }
    return 1;
}

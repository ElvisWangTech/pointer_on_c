//
//  ch04_3.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/11/18.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#include "ch04.h"

void checkTriangle(float a, float b, float c) {
    if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a) {
        printf("不是三角形");
    } else if(a == b == c) {
        printf("等边三角形");
    } else if (a == b || b == c || a == c) {
        printf("等腰三角形");
    } else if (a * a + b * b == c * c || a * a + c * c == b * b || c * c + b * b == a * a) {
        printf("直角三角形");
    } else {
        printf("普通三角形");
    }
    printf("\n");
}

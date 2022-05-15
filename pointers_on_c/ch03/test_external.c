//
//  test_external.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/11/10.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#include "ch03.h"
//extern int dd;
void a () {
    static int x;
    extern int d;
    x = 2;
    printf("%d in function a\n", x);
}

//void b () {
//    int x = 0;
//    printf("%d in function b\n", x);
//}

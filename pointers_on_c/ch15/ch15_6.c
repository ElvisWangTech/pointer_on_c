//
//  ch15_6.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2019/1/25.
//  Copyright © 2019 汪意伟. All rights reserved.
//

#include "ch15.h"
/*
 判断一个整型变量是不是回文，比如： 12321是回文， 12345不是回文
 */
int numeric_palidrome( int value ) {
    char buffer[50];
    sprintf(buffer, "%d", value);
    return palindrome(buffer);
}

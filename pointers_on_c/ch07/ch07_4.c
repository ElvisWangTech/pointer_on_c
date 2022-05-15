//
//  ch07_4.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/12/1.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#include "ch07.h"

int max_list(int values, ...) {
    va_list var_arg;
    // va_start宏初始化，第一个参数是指定的va_list变量，第二个参数是最后一个固定参数
    va_start(var_arg, values);
    
    int max = 0, count, val;
    
    for (count = 0; count < values; count++) {
        // 不能多次访问，用val暂存
        // va_arg宏用来获取参数值，第一个参数是va_list变量，第二个参数是指向的下一个参数类型
        val = va_arg(var_arg, int);
        if (max == 0) {
            max = val;
        } else if (val > max) {
            max = val;
        }
    }
    // var_arg指针设置为NULL
    va_end(var_arg);
    return max;
}

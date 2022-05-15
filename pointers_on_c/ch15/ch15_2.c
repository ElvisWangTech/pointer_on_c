//
//  ch15_2.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2019/1/23.
//  Copyright © 2019 汪意伟. All rights reserved.
//

#include "ch15.h"

void print_std_line(void) {
    char buffer[MAX_SIZE];
    // gets 是不安全的，因为它不判断缓冲区大小，如果缓冲区不够用，多余的字符会覆盖缓冲区后面的内存位置
    // gets 不在缓冲区存储末尾的换行符
    // puts 会自动在末尾添加换行符
    while (gets(buffer) != NULL) {
        puts(buffer);
    }
}

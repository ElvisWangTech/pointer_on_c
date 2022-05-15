//
//  test_print.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2019/1/23.
//  Copyright © 2019 汪意伟. All rights reserved.
//

#include "ch15.h"


void test_print(void) {
    float a = 3.1415926;
    printf("%f\n", a);  // 3.141593
//    float b = 3.14;
    printf("%d\n", 3.14); // 0
    char *s = "ab";
    // - 表示左边对齐，不加表示向右对齐
    // .前的数字表示至少打印出多少字符，不够的补空格
    // .后的数字表示最多保留多少字符，多出的部分末尾截断
    // 以下例子：.表示空格
    printf("%-6.7s\n", s); // ab....
    printf("%6.7s\n", s);  // ....ab
    printf("%2.0s\n", s); // ..
    printf("%6.7s\n", "abcdefgh"); // abcdefg
}

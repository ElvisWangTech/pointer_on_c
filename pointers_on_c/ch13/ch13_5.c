//
//  ch13_5.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2019/1/17.
//  Copyright © 2019 汪意伟. All rights reserved.
//
#include "ch13.h"

/**
 处理短横杠参数

 @param argc 参数个数
 @param argv 参数列表
 @param control 参数规则
 @param do_arg 处理参数的方法
 @param illegal_arg 处理非法参数的方法
 @return 返回下一个命令行参数的指针的指针
 */
char ** do_args(int argc, char **argv, char *control,
                void (*do_arg) ( int ch, char *value ),
                void (*illegal_arg) ( int ch )) {
    // 跳过程序名参数
    char *arg = NULL;
    char *loc = NULL;
    int i = 1;
    int ch;
    while (( arg = argv[i++] ) != NULL && *arg++ == '-' ) {
        while ( ( ch = *arg++ ) != '\0') {
            // ch不在control内， 视为非法参数
            if ( ( loc = strchr(control, ch ) ) == NULL) {
                illegal_arg(ch);
            }
            // ch在ontrol内，且是’带值参数‘，如果有后续字符，则把后续字符当做值传给do_arg，
            // 如果没有后续字符，则把下一个参数当作值传给do_arg
            else if (*(loc + 1) == '+') {
                if (*arg != '\0') {
                    do_arg(ch, arg);
                    // 后续字符如果作为参数值使用则不应该重复处理，此时应该跳出循环
                    break;
                }
                // 下一个参数不存在
                else if(i + 1 < argc) {
                    do_arg(ch, argv[i++]);
                } else {
                    illegal_arg(ch);
                }
            }
            // 下面是字符在control定义内，但是不是带值参数
            else {
                do_arg(ch, NULL);
            }
        }
    }
    return &argv[i-1];
}


/**
 参数处理方法-- 测试用

 @param ch 参数字符
 @param value 参数值
 */
void handle_arg(int ch, char *value) {
    printf("%c: %s\n", ch, value);
}


/**
 非法参数处理方法-- 测试用

 @param ch 参数字符
 */
void handle_illegal_arg(int ch) {
    printf("%c invalid\n", ch);
}

//
//  ch13_1.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2019/1/16.
//  Copyright © 2019 汪意伟. All rights reserved.
//

#include "ch13.h"

int is_unprint(int ch) {
    return !isprint(ch);
}

/* 定义字符类型判断的跳跃表, 返回的是一个函数指针数组 */
int (* test_type[]) (int) = {
    iscntrl, isspace, isdigit, islower, isupper, ispunct, is_unprint
};

/* 定义数组存储累加的结果 */
int sum_ary[] = {
    0, 0, 0, 0, 0, 0, 0
};

/* 定义数组存储字符类型名称 */
char * char_types_description[] = {
    "控制字符", "空白字符", "数字字符", "小写字母", "大写字母", "标点符号", "非打印字符"
};

void count_char_type_new(void) {
    char str[255];
    printf("please input: ");
    scanf("%[^\n]", str);
    
    printf("%s\n", str);
    int total = 0;
    for (int i = 0, ch = str[i]; i < 255 && ch != '\0'; i++, ch = str[i]) {
        total++;
        // 遍历跳跃表中每个方法，如果测试通过则，对应的值+1
        for (int j = 0; j < 7; j++) {
            if (test_type[j](ch)) {
                sum_ary[j]++;
                break;
            }
        }
    }
    
    // 计算百分比， 打印统计结果
    for (int k = 0; k < 7; k++) {
        printf("%s: %.2f%%\n", char_types_description[k], ((float)sum_ary[k] / (float)total) * 100);
    }
    
}

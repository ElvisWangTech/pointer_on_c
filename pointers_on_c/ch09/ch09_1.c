//
//  ch09_1.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/12/23.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#include "ch09.h"

void count_char_type(void) {
    char str[255];
    printf("please input: ");
    /*
     scanf 函数在遇到以下字符时返回， 所以通常不会用scanf捕获字符串，而是用gets或getchar，如果用scanf需要用%[^\n]，表示一行输入
    ① 遇空格、“回车”、“跳格”键。
    ② 遇宽度结束。
    ③ 遇非法输入
     
     从标准输入获取一个字符串的方法：
     第一种写法，包含最后一个换行符
        fgets(str, 255, stdin);
     第二种写法, 不包含的换行符最后
        scanf("%[^\n]", str);
     第三种写法，按字符读取, 优点：可以控制到每个字符
         int ch, i= 0;
         while ((ch = getchar()) != '\n') {
            str[i++] = ch;
         }
         str[i] = '\0';
    */
    scanf("%[^\n]", str);
    
    printf("%s\n", str);
    int sum_cnt = 0;
    int sum_space = 0;
    int sum_digit = 0;
    int sum_lower = 0;
    int sum_upper = 0;
    int sum_punct = 0;
    int sum_unprint = 0;
    for (int i = 0, ch = str[i]; i < 255 && ch != '\0'; i++, ch = str[i]) {
        if (iscntrl(ch)) {
            sum_cnt++;
        } else if (isspace(ch)) {
            sum_space++;
        } else if(isdigit(ch)) {
            sum_digit++;
        } else if(islower(ch)) {
            sum_lower++;
        } else if(isupper(ch)) {
            sum_upper++;
        } else if(ispunct(ch)) {
            sum_punct++;
        } else if (!isprint(ch)) {
            sum_unprint++;
        }
    }
    printf("控制字符: %d\n", sum_cnt);
    printf("空白字符: %d\n", sum_space);
    printf("数字: %d\n", sum_digit);
    printf("小写字母: %d\n", sum_lower);
    printf("大写字母: %d\n", sum_upper);
    printf("标点符号: %d\n", sum_punct);
    printf("不可打印的字符: %d\n", sum_unprint);
}

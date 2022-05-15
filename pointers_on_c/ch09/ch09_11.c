//
//  ch09_11.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/12/31.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#include "ch09.h"

int count_word(const char *path, const char *word) {
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        printf("file open error: %s", path);
        return -1;
    }
    char line[BUFFER_SIZE];
    int sum = 0;
    // 缓存上次查询的位置
    register char *pcur = NULL;
    while(fgets(line, BUFFER_SIZE, fp) != NULL) {
//        printf("%s", line);
        pcur = line;
        while ((pcur = strstr(pcur, word)) != NULL) {
            // 判断上一个字符和下一个字符是否是空白符号, 以空格分割开的说明是一个单词，可以过滤掉像their这样的单词
            if (isspace(*(pcur - 1)) && isspace(*(pcur + strlen(word)))) {
                // 向后移动，跳过当前的word
                sum++;
            }
            pcur += strlen(word);
        }
    }
    printf("%s occurs %d times!\n", word, sum);
        
    return sum;
}

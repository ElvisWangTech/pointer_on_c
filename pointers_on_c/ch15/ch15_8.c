//
//  ch15_8.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2019/1/25.
//  Copyright © 2019 汪意伟. All rights reserved.
//

#include "ch15.h"

/**
 打印文件内容的dump：
 ...
 000200  D405C000 82102004 91D02000 9010207F  *..........*
 000210  82102001 91D02000 0001C000 2F757372  *....../usr*
 ...
 @param fileinput 文件绝对路径
 */
void print_dump(const char *fileinput) {
    FILE *pif;
    pif = fopen(fileinput, "rb");
    if (pif == NULL) {
        perror(fileinput);
        exit(EXIT_FAILURE);
    }
    // 定义缓冲区 每次读取16个字节
    uint8_t buffer[MAX_COUNT];
    size_t pos = 0, num;
    int i, ch;
    uint8_t prts[MAX_COUNT + 1];
    while ( (num = fread(buffer, sizeof(uint8_t), MAX_COUNT, pif) ) > 0) {
        // 打印偏移位置
        printf("%06lX  ", pos);
        // 打印字节的16进制格式
        for (i = 0; i < MAX_COUNT; i++) {
            if (i > 0 && i % 4 == 0) {
                printf(" ");
            }
            // 最后不满16个字节，打印空格
            if (i >= num) {
                printf("  ");
                prts[i] = ' ';
            } else {
                ch = buffer[i];
                printf("%02X", buffer[i]);
                prts[i] = (isspace(ch) || !isprint(ch)) ? '.' : ch;
            }
            
        }
        prts[16] = '\0';
        // 打印两个空格分隔符
        printf("  *%s*\n", prts);
        pos += num;
    }
}

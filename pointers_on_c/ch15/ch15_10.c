//
//  ch15_10.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2019/1/25.
//  Copyright © 2019 汪意伟. All rights reserved.
//

#include "ch15.h"


/**
 计算校验和

 @param stream 输入流
 @return 校验和
 */
long checksum(FILE *stream) {
    size_t num = 0;
    size_t sum = 0;
    while( (num = fgetc(stream)) != EOF) {
        sum += num;
    }
    return sum;
}

/**
 sum -- 计算文件校验和CRC
 原理：
 文件中每个字符做累加，如果超过0xFF,求补码，以此循环，将最终的结果和0xFF做与运算

 @param argc main 参数个数
 @param argv main 参数列表
 @return 成功 1 失败 0
 */
int sum(int argc, const char * argv[]) {
    int cks = 0;
    // 不带参数，从标准输入获取输入字符串
    if (argc <= 1) {
        long result = checksum(stdin);
        printf("%ld\n", result);
    }
    // 带多个参数的情况，判断第二个参数是否是  ‘-f’，如果是，则需要保存校验值到file.cks
    else {
        if (strcmp(*(argv + 1), "-f") == 0) {
            cks = 1;
            argv++;
        }
        while (*++argv != NULL) {
            FILE *fip;
            fip = fopen(*argv, "rb");
            if (fip == NULL) {
                perror(*argv);
                return 0;
            }
            long result = checksum(fip);
            printf("%s: %ld\n", *argv, result);
            if (cks) {
                FILE *fop;
                size_t len = strlen(*argv) + 5;
                char file_cks[len];
                memset(file_cks, '\0', len);
                strcat(file_cks, *argv);
                strcat(file_cks, ".cks");
//                printf("%s", file_cks);
                fop = fopen(file_cks, "w");
                if (fop == NULL) {
                    perror(file_cks);
                } else {
                    fprintf(fop, "%ld\n", result);
//                    fflush(fop);
                    fclose(fop);
                }
            }
            fclose(fip);
        }
    }
    return 1;
}

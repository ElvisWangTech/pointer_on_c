//
//  ch15_9.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2019/1/25.
//  Copyright © 2019 汪意伟. All rights reserved.
//

#include "ch15.h"


/**
 检索字符串

 @param filename 文件路径
 @param stream 文件结构指针
 @param string 检索字符串
 */
void search(const char *filename, FILE *stream, const char *string) {
    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, stream) != NULL) {
        if (strstr(buffer, string) != NULL) {
            if (filename != NULL) {
                printf("%s: ", filename);
            }
            fputs(buffer, stdout);
        }
    }
}

/**
 unix fgrep命令
 fgrep string [file1, file2, ...]

 @param argc main参数数目
 @param argv main参数列表
 */
void fgrep(int argc, const char * argv[]) {
    // 至少要指定一个参数
    if (argc <= 1) {
        fprintf(stderr, "Usage: fgrep string file ...\n");
        exit(EXIT_FAILURE);
    }
    // 要检索的字符串
    const char *string = *++argv;
    // 处理的文件
    if (argc <= 2) {
        search(NULL, stdin, string);
    } else {
        while ( *++argv != NULL ) {
            FILE *stream;
            stream = fopen(*argv, "r");
            if (stream == NULL) {
                perror(*argv);
            } else {
                search(*argv, stream, string);
                fclose(stream);
            }
        }
    }
}

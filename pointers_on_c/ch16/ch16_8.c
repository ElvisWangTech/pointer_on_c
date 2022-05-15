//
//  ch16_8.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2019/2/5.
//  Copyright © 2019 汪意伟. All rights reserved.
//

#include "ch16.h"

#define BUFFER_SIZ 512

/**
 17.00
 35.50
 23.60

 @param fileinput 输入文件
 */
void count_avg_age_new(const char *fileinput) {
    FILE *pif;
    pif = fopen(fileinput, "r");
    if (pif == NULL) {
        perror(fileinput);
        exit(EXIT_FAILURE);
    }
    char buffer[BUFFER_SIZ];
    int age;
    int num = 0;
    float sum = 0;
    char *next;
    while (fgets(buffer, BUFSIZ, pif) != NULL) {
        next = buffer;
        sum = 0;
        num = 0;
        // strtol循环读取
        while (next != NULL && *next != '\n' ) {
            age = (int)strtol(next, &next, 10);
            sum += age;
            num++;
        }
        printf("%5.2f\n", sum / num);
    }
    fclose(pif);
}

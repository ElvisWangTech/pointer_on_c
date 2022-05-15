//
//  ch15_7.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2019/1/25.
//  Copyright © 2019 汪意伟. All rights reserved.
//

#include "ch15.h"

void count_avg_age(const char *fileinput) {
    FILE *pif;
    pif = fopen(fileinput, "r");
    if (pif == NULL) {
        perror(fileinput);
        exit(EXIT_FAILURE);
    }
    char buffer[255];
    int ages[10];
    int num;
    float sum = 0;
    while (fgets(buffer, BUFSIZ, pif) != NULL) {
        // 清零
        memset(ages, 0, 10);
        num = sscanf(buffer, "%d %d %d %d %d %d %d %d %d %d",
               &ages[0], &ages[1], &ages[2], &ages[3], &ages[4],
               &ages[5], &ages[6], &ages[7], &ages[8], &ages[9]);
        // 统计平均值
        sum = 0;
        for (int i = 0; i < num; i++) {
            sum += ages[i];
        }
        printf("%5.2f\n", sum / num);
    }
    fclose(pif);
}

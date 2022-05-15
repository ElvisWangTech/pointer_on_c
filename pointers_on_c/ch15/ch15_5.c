//
//  ch15_5.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2019/1/23.
//  Copyright © 2019 汪意伟. All rights reserved.
//

#include "ch15.h"


int fetch_integers(const char *fileinput, const char *fileoutput) {
    FILE *pif, *pof;
    pif = fopen(fileinput, "r");
    pof = fopen(fileoutput, "a");
    if (pif == NULL || pof == NULL) {
        perror(fileinput);
        exit(EXIT_FAILURE);
    }
    
    char buffer[MAX_SIZE];
    int sum = 0, value = -1;
    while (fgets(buffer, MAX_SIZE, pif) != NULL) {
        // 失败会返回0， 否则返回格式化的参数的个数，这里是1
        if (sscanf(buffer, "%d", &value) == 1) {
            sum += value;
        }
    }
    fprintf(pof, "%d", sum);
    if (fclose(pif) != 0 || fclose(pof)) {
        perror("file close error");
        exit(EXIT_FAILURE);
    }
    return sum;
}

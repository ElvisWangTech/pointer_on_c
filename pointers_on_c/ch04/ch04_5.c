//
//  ch04_5.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/11/18.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#include "ch04.h"

int checkIsDup(char a[], char b[], int n) {
    for(int i = 0; i < n; i++) {
//        printf("%c ", a[i]);
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

void printDupLine(const char * path) {
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        printf("file open error: %s", path);
        return;
    }
    char buffer[BUFFER_SIZE];
    char preLine[BUFFER_SIZE];
    int currentLineNo = 0;
    int preLineNo = 0;
    while(fgets(buffer, BUFFER_SIZE - 1, fp) != NULL) {
        currentLineNo++;
        if (checkIsDup(preLine, buffer, strlen(preLine))) {
            if (preLineNo + 1 < currentLineNo) {
                preLineNo = currentLineNo;
                printf("%s\n", buffer);
            } else {
                preLineNo++;
            }
        }
        strncpy(preLine, buffer, BUFFER_SIZE);
    }
}

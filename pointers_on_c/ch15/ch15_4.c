//
//  ch15_4.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2019/1/23.
//  Copyright © 2019 汪意伟. All rights reserved.
//

#include "ch15.h"

int copy_file(const char *fileinput, const char *fileoutput) {
    FILE *pif, *pof;
    pif = fopen(fileinput, "r");
    pof = fopen(fileoutput, "w");
    if (pif == NULL || pof == NULL) {
        perror(fileinput);
        exit(EXIT_FAILURE);
    }
    
    char buffer[MAX_SIZE];
    while (fgets(buffer, MAX_SIZE, pif) != NULL) {
        fputs(buffer, pof);
    }
    
    if (fclose(pif) != 0 || fclose(pof)) {
        perror("file close error");
        exit(EXIT_FAILURE);
    }
    return 1;
}

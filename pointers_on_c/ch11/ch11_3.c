//
//  ch11_3.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2019/1/7.
//  Copyright © 2019 汪意伟. All rights reserved.
//

#include "ch11.h"

char *read_str_dup(void) {
    char str[255];
    scanf("%[^\n]", str);
    char *new_str_dup;
    new_str_dup = malloc((strlen(str) + 1) * sizeof(char));
    if (new_str_dup != NULL) {
        strcpy(new_str_dup, str);
    }
    return new_str_dup;
}

//
//  ch15_3.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2019/1/23.
//  Copyright © 2019 汪意伟. All rights reserved.
//

#include "ch15.h"

void print_std_line2(void) {
    char buffer[MAX_SIZE];
    // fgets
    while (fgets(buffer, MAX_SIZE, stdin) != NULL) {
        fputs(buffer, stdout);
    }
}

//
//  ch16_1.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2019/2/1.
//  Copyright © 2019 汪意伟. All rights reserved.
//

#include "ch16.h"

void get_min_base(void) {
    printf("enter age: ");
    char age[4];
    gets(age);
    int base;
    long result;
    
    long ss = strtod(age, NULL);
    char aaa[3];
    for (int i = 29; i > 0; i--) {
        sprintf(aaa, "%d", i);
        for (base = 2; base <= 36; base++) {
            result = strtol(aaa, NULL, base);
            if (ss == result) {
                printf("min base is: %d\n", base);
                return;
            }
        }
    }
    printf("can not found.\n");
}

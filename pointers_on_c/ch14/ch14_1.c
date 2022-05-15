//
//  ch14_1.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2019/1/18.
//  Copyright © 2019 汪意伟. All rights reserved.
//

#include "ch14.h"

void print_ledger_default(int data) {
    printf("default: %d\n", data);
}

void print_ledger_long(int data) {
    printf("long: %d\n", data);
}

void print_ledger_detailed(int data) {
    printf("detailed: %d\n", data);
}

void print_ledger(int data) {
#if defined OPTION_LONG
    #define OK 1
    print_ledger_long(data);
#elif defined OPTION_DETAILED
    #define OK 1
    print_ledger_detailed(data);
#endif
    
#ifndef OK
    print_ledger_default(data);
#endif
}

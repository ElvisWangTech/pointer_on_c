//
//  ch10_7.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2019/1/6.
//  Copyright © 2019 汪意伟. All rights reserved.
//

#include "ch10.h"

void print_nodes(void) {
    struct NODE nodes[5] = {
        {5, nodes + 3, NULL},
        {15, nodes + 4, nodes + 3},
        {22, NULL, nodes + 4},
        {12, nodes + 1, nodes},
        {18, nodes + 2, nodes + 1}
    };
    
    struct NODE *np = nodes + 2;
    struct NODE **npp = &nodes[1].b;
    printf("%u", np);
    
}

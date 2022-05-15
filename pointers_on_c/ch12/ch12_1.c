
//
//  ch12_1.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2019/1/8.
//  Copyright © 2019 汪意伟. All rights reserved.
//

#include "ch12.h"

int get_sll_size(Node **listp) {
    Node *current;
    int sum = 0;
    for (current = *listp; current != NULL; current = current->link) {
        sum++;
    }
    return sum;
}

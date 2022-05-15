//
//  ch12_2.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2019/1/16.
//  Copyright © 2019 汪意伟. All rights reserved.
//

#include "ch13.h"

void find_node_with_callback(Node *first, void (*func)(Node *)) {
    register Node *this;
    for (this = first; this != NULL; this = this->link) {
        func(this);
    }
}

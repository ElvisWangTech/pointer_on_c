//
//  ch12_6.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2019/1/9.
//  Copyright © 2019 汪意伟. All rights reserved.
//

#include "ch12.h"

int dll_remove( DNode **rootp, DNode *node ) {
    // 空链表，返回-1
    if (rootp == NULL) {
        return -1;
    }
    DNode *this;
    DNode *prev;
    DNode *next;
    for (this = prev = *rootp; (next = this->fwd) != NULL; prev = this, this = next) {
        if (this == node) {
            // 首节点
            if (this == prev) {
                *rootp = next;
                next->bwd = NULL;
            } else {
                prev->fwd = next;
                next->bwd = prev;
                this->bwd = NULL;
            }
            this->fwd = NULL;
            break;
        }
    }
    // 尾节点
    if (next == NULL) {
        this->bwd = NULL;
        prev->fwd = NULL;
    }
    return 1;
}

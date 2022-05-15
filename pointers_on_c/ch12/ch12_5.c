//
//  ch12_5.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2019/1/8.
//  Copyright © 2019 汪意伟. All rights reserved.
//

#include "ch12.h"

/* 从单链表中移除一个节点 */
int sll_remove( Node **rootp, Node *node ) {
    // 空链表，返回-1
    if (rootp == NULL) {
        return -1;
    }
    Node *this;
    Node *prev;
    for (this = prev = *rootp; (this = this->link) != NULL; prev = this) {
        if (this == node) {
            // 首节点
            if (this == prev) {
                *rootp = this->link;
            } else {
                prev->link = this->link;
            }
            this->link = NULL;
        }
    }
    return 1;
}

//
//  ch12_4.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2019/1/8.
//  Copyright © 2019 汪意伟. All rights reserved.
//

#include "ch12.h"
/* 反序排列单链表的所有节点 */
Node *sll_reverse(Node *first) {
    // 空链表返回NULL
    if (first == NULL) {
        return NULL;
    }
    Node *next=first->link;
    Node *nextnext;
    Node *this = first;
    // 首节点必须指向NULL, 否则会形成闭环
    first->link = NULL;
    while (next != NULL) {
        nextnext = next->link;
        next->link = this;
        this = next;
        next = nextnext;
    }
    
    return this;
}

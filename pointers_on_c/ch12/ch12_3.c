//
//  ch12_3.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2019/1/8.
//  Copyright © 2019 汪意伟. All rights reserved.
//

#include "ch12.h"

int dll_insert (register DNode *rootp, int value) {
    register DNode *this;
    register DNode *next;
    register DNode *newnode;
    
    for (this = rootp; (next = this->fwd) != NULL; this = next) {
        // 如果有值存在，直接返回
        if (this->value == value) {
            return 0;
        } else if (this->value > value) {
            break;
        }
    }
    
    newnode = (DNode *)malloc(sizeof(DNode));
    if (newnode == NULL) {
        return -1;
    }
    newnode->value = value;
    
    // 把新节点添加到链表中
    // 新节点的下一个节点指向当前节点
    newnode->fwd = this;
    if (this != rootp) {
        // 新节点的上一个节点指向当前节点的上一个节点
        newnode->bwd = this->bwd;
        // 当前节点上一个节点指向新节点
        this->bwd->fwd = newnode;
    } else {
        newnode->bwd = NULL;
    }
    // 当前节点的上一个节点指向新节点
    this->bwd = newnode;
    
    return 1;
}

/* 优点可以直接修改头尾节点 */
int dll_insert_new (register DNode *head, register DNode *rear, int value) {
    register DNode *this;
    register DNode *next;
    register DNode *newnode;
    
    for (this = head; (next = this->fwd) != NULL; this = next) {
        // 如果有值存在，直接返回
        if (this->value == value) {
            return 0;
        } else if (next->value > value) {
            break;
        }
    }
    
    newnode = (DNode *)malloc(sizeof(DNode));
    if (newnode == NULL) {
        return -1;
    }
    newnode->value = value;
    
    // 把新节点添加到链表中
    if (this == head) {
        head = newnode;
    } else {
        this->fwd = newnode;
    }
    // 空链表或者到达尾部, 新节点作为尾节点, 否则插入当前节点后面，next节点前面
    if (head == NULL || next == NULL) {
        rear = newnode;
    } else {
        next->bwd = newnode;
    }
    
    newnode->fwd = next;
    newnode->bwd = this;
    
    return 1;
}

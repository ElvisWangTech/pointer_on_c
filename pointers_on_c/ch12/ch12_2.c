//
//  ch12_2.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2019/1/8.
//  Copyright © 2019 汪意伟. All rights reserved.
//

#include "ch12.h"

Node *get_node(Node *first, int value) {
    register Node *this;
    for (this = first; this != NULL; this = this->link) {
        if (this->value == value) {
            return this;
        }
    }
    return NULL;
}

DNode *get_dnode(DNode *first, int value) {
    register DNode *this;
    for (this = first; this != NULL; this = this->fwd) {
        if (this->value == value) {
            return this;
        }
    }
    return NULL;
}

void print_nodes_val(Node *first) {
    register Node *this;
    for (this = first; this != NULL; this = this->link) {
        printf("%d ", this->value);
    }
    printf("\n");
}

void print_node_val(Node *p_node) {
    if (p_node == NULL) {
        printf("null value");
    } else {
         printf("%d", p_node->value);
    }
}

void print_dnodes(DNode *first) {
    register DNode *this;
    register DNode *prev=NULL;
    register DNode *next;
    for (this = first; (next = this->fwd) != NULL; prev = this, this = next) {
        printf("prev: %d this: %d next: %d\n",
               prev == NULL?INT_MIN: prev->value,
               this == NULL?INT_MIN: this->value,
               next == NULL?INT_MIN: next->value);
    }
}

Node *new_node_new(int value) {
    Node *np = NULL;
    np = (Node *)malloc(sizeof(Node));
    np->value = value;
    return np;
}

DNode *new_dnode(int value) {
    DNode *dnp = NULL;
    dnp = (DNode *)malloc(sizeof(DNode));
    dnp->bwd = NULL;
    dnp->fwd = NULL;
    dnp->value = value;
    return dnp;
}

/* 生成一个单链表用来测试 */
Node *gen_nodes_new(void) {
    Node *head;
    head = new_node_new(5);
    head->link = new_node_new(10);
    head->link->link = new_node_new(15);
    return head;
}

/* 生成一个双链表用来测试 */
DNode *gen_dnodes_new(void) {
    DNode *head;
    head = new_dnode(5);
    DNode *second = new_dnode(10);
    head->fwd = second;
    second->bwd = head;
    DNode *third = new_dnode(15);
    second->fwd = third;
    third->bwd = second;
    return head;
}

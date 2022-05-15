//
//  ch11_4.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2019/1/7.
//  Copyright © 2019 汪意伟. All rights reserved.
//

#include "ch11.h"

Node *new_node(int value) {
    Node *np = NULL;
    np = (Node *)malloc(sizeof(Node));
    np->value = value;
    return np;
}

Node *gen_nodes(void) {
    Node *head;
    head = new_node(5);
    head->next = new_node(10);
    head->next->next = new_node(15);
    return head;
}

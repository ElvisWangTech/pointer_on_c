//
//  ch12.h
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/12/23.
//  Copyright © 2018 汪意伟. All rights reserved.
//
#ifndef ch12_h
#define ch12_h

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
/* 双链表的结构定义 */
typedef struct NODE{
    struct NODE *link;  // 指向下一个节点的指针
    int value;
} Node;

/* 双链表的结构定义 */
typedef struct DNODE {
    struct DNODE *fwd; // 指向下一个节点的指针
    struct DNODE *bwd; // 指向上一个节点的指针
    int value;
} DNode;

/* 获取单链表的节点数目 */
int get_sll_size(Node **listp);

/* 在一个无序的单链表中找到一个特定的值，并返回指向该节点的指针 */
Node *get_node(Node *first, int value);

/* 在一个无序的双链表中找到一个特定的值，并返回指向该节点的指针 */
DNode *get_dnode(DNode *first, int value);

/* 生成一个单链表用来测试 */
Node *gen_nodes_new(void);

/* 生成一个双链表用来测试 */
DNode *gen_dnodes_new(void);

/* 打印双链表的值用来测试 */
void print_dnodes(DNode *first);

/* 打印单链表的值用来测试 */
void print_nodes_val(Node *first);

/* 打印单个节点的值用来测试 */
void print_node_val(Node *p_node);

/* 插入新的节点到双链表 */
int dll_insert (register DNode *rootp, int value);

/* 插入新的节点到双链表的另一种实现 */
int dll_insert_new (register DNode *head, register DNode *rear, int value);

/* 反序排列单链表的所有节点 */
Node *sll_reverse(Node *first);

/* 从单链表中移除一个节点 */
int sll_remove( Node **rootp, Node *node );

/* 从双链表中移除一个节点 */
int dll_remove( DNode **rootp, DNode *node );

/* 建立一个字母索引表，并把新单词插入到这个索引表中 */

#endif /* ch12_h */

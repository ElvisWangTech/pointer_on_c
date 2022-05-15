//
//  ch08_8.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/12/9.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#include "ch08.h"

// 皇后，queens[1] = 1表示第一个皇后在第1行到第1列位置
static int queens[9] = {-1,-1,-1,-1,-1,-1,-1,-1,-1};

/*
 检测是否冲突
 
 */
int check(int queen_id, int pos) {
    for (int i = 1; i < queen_id; i++) {
        if (queens[i] == pos || abs(queens[i] - pos) == queen_id - i ) {
            return 1;
        }
    }
    return 0;
}

/*
 打印皇后的位置
 */
void draw() {
    int pos;
    printf("\n---------------\n");
    for (int i = 1; i <= 8; i++) {
        pos = queens[i];
        for (int j = 1; j <= 8; j++) {
            printf("%c ", (j==pos)?'1':'0');
        }
        printf("\n");
    }
    printf("---------------\n");
}

/*
 放置新的皇后到下一行
 */
void put(int queen_id, int pos) {
    if (queen_id <= 0) return;
    while (check(queen_id, pos++) && pos <= 9)
        ;
    // 超出边界需要进行回溯，否则放置下一个皇后
    if (pos > 9) {
        // printf("backtracking..\n");
        put(queen_id-1, queens[queen_id - 1] + 1);
    } else {
        // printf("put next queen\n");
        queens[queen_id] = pos-1;
        if (queen_id < 8) {
            put(queen_id+1, 1);
        } else {
            draw();
        }
        
    }
    
}

/*
 国际象棋里把8个皇后放在8*8的棋盘上，要求其中任何一个都无法攻击到其余的皇后，求一共有多少种摆法？
 思路：一行一行的摆皇后，直到摆满8行，如果摆的过程中发生冲突，则移动到下一列，如果已经到最后一列，则调整上一行的皇后的位置到下一列
 直到不冲突的时候函数返回，重新摆下一行的皇后
 
 如果摆满8行，及求出一个解
 
 */
void test_eight_queens() {
    // 将第一个皇后放到第一行第一列的位置
    put(1, 1);
}

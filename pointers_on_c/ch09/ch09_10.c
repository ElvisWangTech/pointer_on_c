//
//  ch09_10.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/12/23.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#include "ch09.h"

int palindrome(char *string) {
    int ch;
    int len = strlen(string);
    int buffer[len];
    int i = 0, front, rear, new_len = 0;
    printf("len: %d\n", len);
    while ((ch = *string++) != '\0') {
        if (isalpha(ch)) {
            ch = tolower(ch);
            buffer[i++] = ch;
            new_len++;
        }
    }
    front = 0;
    rear = new_len - 1;
    while (front < rear) {
        if (buffer[front] != buffer[rear])
            break;
        front += 1;
        rear -= 1;
    }
    return front >= rear;
}

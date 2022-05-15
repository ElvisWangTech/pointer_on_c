//
//  test_palindrome.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/12/8.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#include "ch08.h"

int test_palindrome_v2(char buffer[]) {
    char *p = buffer;
    
    int len = strlen(buffer), i = 0, flag = 0;
    
    while (*(p+len-i-1) == *(p+i)) {
        if (i >= len/2) {
            flag = 1;
            break;
        }
        i++;
    }
    if (flag) {
        printf("It is a palindrome!\n");
    } else {
        printf("It is not a palindrome!\n");
    }
    return flag;
}

int test_palindrome(char buffer[]) {
    int front, rear;
    
    front = 0;
    rear = strlen(buffer) - 1;
    while (front < rear) {
        if (buffer[front] != buffer[rear])
            break;
        front += 1;
        rear -= 1;
    }
    int flag = front >= rear;
    if (flag) {
        printf("It is a palindrome!\n");
    } else {
        printf("It is not a palindrome!\n");
    }
    return flag;
}

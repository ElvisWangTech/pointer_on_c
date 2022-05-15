//
//  ch09.h
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/12/23.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#ifndef ch09_h
#define ch09_h

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>
#include <assert.h>

// 统计字符类型
void count_char_type(void);
// strlen函数
size_t my_strlen(char const *string, int max_len);
// my_strcpy
char *my_strcpy(char *dst, const char *src, int dest_len);
// my_strcat
char *my_strcat(char *dst, char const *src, int dest_len);
// my_strncat
void my_strncat(char *dst, char const *src, size_t n, int dest_len);
// my_strcpy_end
char *my_strcpy_end(char *dst, const char *src);
// my_strrchr
char *my_strrchr(char const *str, int ch);
// my_strnchr
char *my_strnchr(char const *str, int ch, int which);
// count_chars, 统计字符数量
int count_chars(char const *str, char const *chars);
// palindrome回文判断, 要求忽略掉非字母数字，且不区分大小写
int palindrome(char *string);
// 从标准输入统计单词'the'出现的次数
int count_word(const char *path, const char *word);

#define BUFFER_SIZE 100

// 字符串加密解密
int prepare_key(char const *key);
void encrypt_string(char *data, char const *key);
void decrypt_string(char *data, char const *key);

// 把数字字符串（以美分为单位）转换为美元的形式输出
void dollars(char *dest, char const *src);
#endif /* ch09_h */

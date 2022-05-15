//
//  ch09_12.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/12/31.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#include "ch09.h"

static char prepared_key[27];
static char alpha_table[26];
static int is_key_prepared = 0;

int prepare_key(char const *key){
    if (key == NULL) {
        return 0;
    }
    // 初始化prepared_key
    for (int i = 0; i < 27; i++) {
        prepared_key[i] = '\0';
    }
    // 初始化alpha_table
    for (int i = 0; i < 26; i++) {
        alpha_table[i] = 0;
    }
    int index = 0;
    int ch;
    while (*key != '\0') {
        if (!isalpha(*key)) {
            return 0;
        }
        // 过滤重复的
        ch = toupper(*key);
        if (strchr(prepared_key, ch) == NULL) {
            prepared_key[index++] = ch;
            // 字母为已选择
            alpha_table[ch - 65] = 1;
        }
        key++;
    }
    for (int i = 0; i < 26; i++) {
        if (alpha_table[i]) {
            continue;
        } else {
            prepared_key[index++] = i + 65;
        }
    }
    printf("prepared! the key is: %s \n", prepared_key);
    return 1;
}
void encrypt_string(char *data, char const *key) {
    if (!is_key_prepared) {
        prepare_key(key);
    }
    int len = strlen(data);
    char encryped_data[len + 1];
    encryped_data[len] = '\0';
    int ch, ch_upper, index = 0;
    char *p = data;
    while ((ch = *p++) != '\0') {
        if (isalpha(ch)) {
            ch_upper = prepared_key[toupper(ch) - 65];
            encryped_data[index++] = isupper(ch) ? ch_upper : tolower(ch_upper);
        } else {
            encryped_data[index++] = ch;
        }
    }
    printf("encryped ! \noriginal data: %s \nencryped data: %s \n", data, encryped_data);
}
void decrypt_string(char *data, char const *key) {
    if (!is_key_prepared) {
        prepare_key(key);
    }
    int len = strlen(data);
    char decryped_data[len + 1];
    decryped_data[len] = '\0';
    int ch, ch_upper, index = 0;
    char *p = data, *ptr = prepared_key;
    while ((ch = *p++) != '\0') {
        if (isalpha(ch)) {
            ch_upper = toupper(ch);
            if ((ptr = strchr(prepared_key, ch_upper)) != NULL) {
                ch_upper = ptr - prepared_key + 65;
            }
            decryped_data[index++] = isupper(ch) ? ch_upper : tolower(ch_upper);
        } else {
            decryped_data[index++] = ch;
        }
    }
    printf("decryped ! \noriginal data: %s \ndecryped data: %s \n", data, decryped_data);
}

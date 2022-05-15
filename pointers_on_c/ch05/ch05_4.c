//
//  ch05_4.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/11/18.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#include "ch05.h"

unsigned character_offset(unsigned bit_number) {
    return bit_number / CHAR_BIT;
}

unsigned bit_offset(unsigned bit_number) {
    return bit_number % CHAR_BIT;
}

void set_bit(char bit_array[], unsigned bit_number) {
    bit_array[character_offset(bit_number)] |= 1 << bit_offset(bit_number);
}
void clear_bit(char bit_array[], unsigned bit_number) {
    bit_array[character_offset(bit_number)] &= ~(1 << bit_offset(bit_number));
}
void assign_bit(char bit_array[], unsigned bit_number, int value) {
    if(value != 0) {
        set_bit(bit_array, bit_number);
    } else {
        clear_bit(bit_array, bit_number);
    }
}
int test_bit(char bit_array[], unsigned bit_number) {
    return bit_array[character_offset(bit_number)] & 1 << bit_offset(bit_number);
}

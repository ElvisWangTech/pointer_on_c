//
//  ch08_1.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/12/8.
//  Copyright © 2018 汪意伟. All rights reserved.
//

#include "ch08.h"

void def_char_value() {
    int char_value[3][6][4][5] = {
        {},
        {
            {},
            {
                {},
                {
                    0,' '
                }
            },
            {
                {},
                {},
                {
                    0, 0, 0, 'A'
                },
                {
                    0, 0, 0, 0, 'x'
                }
            },
            {
                {},
                {},
                {
                    0, 0, 0xf3
                }
            },
            {
                {},
                {},
                {
                    0, 0, 0, '\n'
                }
            }
        },
        {
            {},
            {
                {},
                {
                    0, 0, 0320
                }
            },
            {
                {},
                {
                    0, '0'
                },
                {
                    0, 0, '\''
                },
                {
                    0, '\121'
                }
            },
            {},
            {
                {},
                {},
                {},
                {
                    0, 0, '3', 3
                }
            },
            {
                {},
                {},
                {},
                {
                    0, 0, 0, 0, 125
                }
            }
        }
    };
    printf("{1,2,2,3} %c\n", char_value[1][2][2][3]);
    printf("{1,1,1,1} %c\n", char_value[1][1][1][1]);
    printf("{1,3,2,2} %x\n", char_value[1][3][2][2]);
    printf("{2,4,3,2} %c\n", char_value[2][4][3][2]);
    printf("{1,4,2,3} %d\n", char_value[1][4][2][3]);
    printf("{2,2,3,1} %d\n", char_value[2][2][3][1]);
    printf("{2,4,3,3} %d\n", char_value[2][4][3][3]);
    printf("{2,5,3,4} %d\n", char_value[2][5][3][4]);
    printf("{1,2,3,4} %c\n", char_value[1][2][3][4]);
    printf("{2,1,1,2} %d\n", char_value[2][1][1][2]);
    printf("{2,2,2,2} %c\n", char_value[2][2][2][2]);
    printf("{2,2,1,1} %c\n", char_value[2][2][1][1]);
}

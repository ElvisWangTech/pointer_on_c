//
//  ch16_3.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2019/2/1.
//  Copyright © 2019 汪意伟. All rights reserved.
//

#include "ch16.h"

void speek_time_baby(void) {
    struct tm *tm;
    time_t now = time(0);
    tm = localtime(&now);
    
    // strftime 用于格式话tm， mktime用于把一个tm结构转换为time_t值
    
//    printf("时针在%d上面，分针在%d上面\n",
//           tm->tm_hour > 12? tm->tm_hour - 12: tm->tm_hour,
//           tm->tm_min);
    
    // 1 在某个数字上，2 在某两个数字之间
    // 比如6:00，时针在数字6上， 分针在数字12h上
    // 14:52, 时针在2和3之间，分针在10和11之间
    
    int hour = tm->tm_hour;
    int min = tm->tm_min;
    int hour_12 = hour > 12? hour - 12: hour;
    // 第一种情况， 整点
    if (min == 0) {
        printf("时针在%d上面，分针在%d上面\n", hour_12, min);
    }
    // 第二种情况， 分钟在数字上，时针在两个数字之间
    else if ( min % 5 == 0 ) {
        printf("时针在%d和%d之间，分针在%d上面\n", hour_12, hour_12 + 1, min / 5);
    }
    // 第三种情况， 分钟和时钟都在两个数字之间
    else {
        printf("时针在%d和%d之间，分针在%d和%d之间\n", hour_12, hour_12 + 1, min / 5, min / 5 + 1);
    }
}

//
//  ch16_5.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2019/2/5.
//  Copyright © 2019 汪意伟. All rights reserved.
//

#include "ch16.h"


/**
 计算风寒度

 @param temp 摄氏气温度数
 @param velocity 风速 米/秒
 @return 风寒度
 */
double wind_chill(double temp, double velocity) {
    double const_a = 10.45;
    int const_b = 10;
    int const_c = -1;
    double const_x = 1.78816;
    
    double delta_temp = 33 - temp;
    double wind_chill = delta_temp * (const_a + const_b * sqrt(velocity) + const_c * velocity)/
        (const_a + const_b * sqrt(const_x) + const_c * const_x);
    return wind_chill;
}

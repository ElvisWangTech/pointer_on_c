//
//  questions.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2019/2/1.
//  Copyright © 2019 汪意伟. All rights reserved.
//

#include "ch16.h"

void handle_signo(int signo) {
    printf("is SIGFPE? %d\n", signo  == SIGFPE);
}

void test_questions(void) {
    long result = strtol("12345", NULL, -5);
    printf("%ld\n", result);
    
//    int i;
//    for (i = 0; i < 100; i += 1) {
//        printf("%d\n", rand() % 2);
//    }
    
    /*
     clock返回从秩序开始执行处理器所消耗的时间，通常是处理器时钟的滴答次数，如果需要转换成秒，需要除以常量 CLOCKS_PER_SEC
     以下是判断clock函数用的cpu时间是cpu使用时间还是总流逝时间
     */
    // clock_t is unsigned long
//    clock_t start, finish;
//    double totaltime;
//    start = clock();
//    for (int i = 0; i < 10000000; i++) {
//
//    }
//    finish = clock();
//    totaltime = (double)(finish - start)/CLOCKS_PER_SEC;
//    printf("totaltime is : %.2lf\n", totaltime);
    
    /* 打印军事格式的时间 */
//    struct tm *tm;
//    time_t now;
//
//    now = time(0);
//    tm = localtime(&now);
//    printf("%d:%02d:%02d %d/%02d/%02d\n",
//           tm->tm_hour, tm->tm_min, tm->tm_sec,
//           tm->tm_mon, tm->tm_mday + 1, tm->tm_year + 1900);
    
    /* 测试长跳转， 非本地跳转 */
//    jmp_buf jbuf;
//    int a = 1, b = 1;
//    setjmp(jbuf);
//    printf("%d plus %d equals %d\n", a, b, a + b);
//    longjmp(jbuf, 1);
//    printf("After longjmp\n");
    
    /* 判断SIGFPE */
    
    if ( SIG_ERR == signal(SIGFPE, handle_signo)  ) {
        return;
    }
    int a = 1;
    int b = 0;
    printf("%d\n", a / b);
}

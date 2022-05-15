//
//  ch15_11.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2019/1/26.
//  Copyright © 2019 汪意伟. All rights reserved.
//

#include "ch15.h"

#define REC_CSV "/Users/wangyiwei/tmp/record.csv"
#define LINE_BUF_SIZE 61
#define EMPTY_TAG 32
#define END_TOKEN '\n'
#define SEPERATOR "============"

// 定义零件的结构体
typedef struct {
    int part_num;           // 零件号
    char description[20];   // 描述信息
    int quantity;           // 数量
    float cost_each;        // 单价
    
} Part;

// 定义存货记录头部结构体
typedef struct {
    int part_num_avail;     // 最近可用的零件号
} RecHead;

void test_atexit() {
    printf("before exiting.");
}

/**
 打印使用方法
 */
void help() {
    printf("welcome!\n");
    printf("0 new description, quantity, cost-each\n");
    printf("1 buy part-number, quantity, cost-each\n");
    printf("2 sell part-number, quantity, price-each\n");
    printf("3 delete part-number\n");
    printf("4 print part-number\n");
    printf("5 print_all\n");
    printf("6 total\n");
    printf("7 end\n");
    printf("8 help\n");
}

/**
 去除字符串首尾空白字符

 @param str 源字符串
 @return trim后字符串
 */
char *trim(char *str) {
    char *p = str;
    while (*p == ' ' || *p == '\t' || *p == '\r' || *p == '\n')
        p ++;
    str = p;
    p = str + strlen(str) - 1;
    while (*p == ' ' || *p == '\t' || *p == '\r' || *p == '\n')
        -- p;
    *(p + 1) = 0;
    return str;
}

/**
 获取标准输入字符串, 通过end_token结束输入且不包含end_token

 @param str 字符数组
 @param end_token 结束字符
 */
void stdin_get(char str[], char end_token) {
    int ch, i= 0;
    size_t len = strlen(str);
    while ((ch = getchar()) != end_token && i < len - 1) {
        str[i++] = ch;
    }
    str[i] = '\0';
    ungetc(end_token, stdin);
}

/**
 检测用户输入的零件号是否合法

 @param part_num 零件号
 @return 1 合法 0 非法
 */
int check_input_part_num(int part_num) {
    if (part_num <= 0) {
        printf("your input part part_num is invalid or too large\n");
        return 0;
    }
    return 1;
}

/**
 检测用户输入的零件数目是否合法

 @param quantity 零件数
 @return 1 合法 0 非法
 */
int check_input_quantity(int quantity) {
    if (quantity <= 0 || quantity > 999999) {
        printf("your input part quantity is invalid or too large\n");
        return 0;
    }
    return 1;
}

/**
  检测用户输入的零件单价是否合法

 @param cost_each 零件单价
 @return 1 合法 0 非法
 */
int check_input_cost_each(float cost_each) {
    if (cost_each < 0 || cost_each > 9999999.00) {
        printf("your input part cost each price is invalid or too large\n");
        return 0;
    }
    return 1;
}

/**
 检测用户输入的零件描述是否合法

 @param desc 零件描述
 @return 1 合法 0 非法
 */
int check_input_desc(char *desc) {
    if (strlen(trim(desc)) == 0) {
        printf("your input part description is invalid\n");
        return 0;
    }
    return 1;
}

/**
 获取行数据缓冲区
 
 @return 缓冲区数组
 */
char *get_buffer_line() {
    static char buffer[LINE_BUF_SIZE];
    // 初始化,NUL填充
    memset(buffer, 0, LINE_BUF_SIZE);
//    buffer[LINE_BUF_SIZE - 2] = '\n';
    return buffer;
}

/**
 解析零件信息

 @param buffer 缓冲区
 @param p 零件结构体
 @return 零件结构体
 */
Part *resolve_part(char *buffer, Part *p) {
    // 以‘:’为分割符进行分割
    char *token;
    int step = 0;
    if (p == NULL) {
        p = (Part *)malloc(sizeof(Part));
    }
    for (token = strtok(buffer, ":"); token != NULL; token = strtok(NULL, ":")) {
        if (step == 0) {
            sscanf(token, "%d", &(p->part_num));
        } else if (step == 1) {
//            sscanf(token, "%s", p->description);
            strncpy(p->description, token, 20);
            p->description[19] = '\0';
        } else if (step == 2) {
            sscanf(token, "%d", &(p->quantity));
        } else if (step == 3) {
            sscanf(token, "%f", &(p->cost_each));
        }
        step++;
    }
    return p;
}


/**
 获取可分配的零件号

 @param fip 存货记录文件指针
 @return 零件h号
 */
int get_avail_part_num(FILE *fip) {
    char *buffer = get_buffer_line();
    int part_num = 0;
    rewind(fip);
    // 处理第一行数据, 如果有记录最近零件号则跳转到指定的行
    fgets(buffer, LINE_BUF_SIZE, fip);
    if (strlen(buffer) > 1) {
        RecHead *head = (RecHead *)malloc(sizeof(RecHead));
        sscanf(buffer, "%d", &(head->part_num_avail));
//        printf("test1: %s", buffer);
        // 跳转到指定的位置
        fseek(fip, head->part_num_avail * LINE_BUF_SIZE, SEEK_SET);
        part_num = head->part_num_avail;
    }
    // 第一行都没有数据，表示空文件, 需要先写入头部信息
    else {
        part_num = 1;
//        sprintf(buffer, "%10d%49c\n", part_num, EMPTY_TAG);
        fprintf(fip, "%10d%49c\n", part_num, EMPTY_TAG);
//        fputs(buffer, fip);
        return part_num;
    }
    while (fgets(buffer, LINE_BUF_SIZE, fip) != NULL) {
        // 解析零件信息
        Part *part = (Part *)malloc(sizeof(Part));
        resolve_part(buffer, part);
        // 描述信息为空，表示该零件被删除
        char * desc_trim = trim(part->description);
        long len = strlen(desc_trim);
        free(part);
        if (len == 0) {
            break;
        }
        part_num++;
    }
    // 将可用的零件号写入到头部信息  -- 要用r+模式打开，a+只能在末尾添加
    sprintf(buffer, "%10d", part_num);
    rewind(fip);
    fputs(buffer, fip);
    fflush(fip);
    printf("next available part number is: %d\n", part_num);
    return part_num;
}

/**
 创建新的零件记录

 @param fip 存货记录文件指针
 */
void new(FILE *fip) {
    char description[20];
    int quantity;
    float cost_each;
    printf("description: ");
//    scanf("%s", description);
    stdin_get(description, '\n');
    if (!check_input_desc(description)) {
        return;
    }
    printf("quantity: ");
    scanf("%d", &quantity);
    if (!check_input_quantity(quantity)) {
        return;
    }
    printf("cost_each: ");
    scanf("%f", &cost_each);
    if (!check_input_cost_each(cost_each)) {
        return;
    }
    
//    printf("%s\n%d\n%lf", description, quantity, cost_each);
    // 获取可分配的零件号，并在头部即首行位置记录这个可分配的零件号
    int part_num = get_avail_part_num(fip);
    // 定位到指定的行
    long offset = part_num * LINE_BUF_SIZE;
    fseek(fip, offset, SEEK_SET);
    // 写入零件信息
//    char *buffer = get_buffer_line();
//    sprintf(buffer, "%10d:%-20.20s:%6d:%7.2f:%9c\n", part_num, description, quantity, cost_each, EMPTY_TAG);
    fprintf(fip, "%10d:%-20.20s:%6d:%7.2f:%9c\n", part_num, description, quantity, cost_each, EMPTY_TAG);
//    printf("test2: %s", buffer);
//    fputs(buffer, fip);
    // 指定到起始位置
    rewind(fip);
    printf("operation is ok!\n");
}

/**
 购买一定数量的零件, 然后重新计算单价, 并不保存购买记录
 

 @param fip 存货记录文件指针
 */
void buy(FILE *fip) {
    int part_num;
    printf("part number: ");
    scanf("%d", &part_num);
    
    if (!check_input_part_num(part_num)) {
        return;
    }
    int quantity;
    printf("quantity: ");
    scanf("%d", &quantity);
    if (!check_input_quantity(quantity)) {
        return;
    }
    float cost_each;
    printf("cost_each: ");
    scanf("%f", &cost_each);
    if (!check_input_cost_each(cost_each)) {
        return;
    }
    
    long offset = part_num * LINE_BUF_SIZE;
    fseek(fip, offset, SEEK_SET);
    char *buffer = get_buffer_line();
    fgets(buffer, LINE_BUF_SIZE, fip);
    if (strlen(buffer) > 0) {
        Part *part = (Part *)malloc(sizeof(Part));
        resolve_part(buffer, part);
        
        // 计算新的总价值
        double new_cost = part->cost_each * part->quantity + quantity * cost_each;
        int new_quantity = part->quantity + quantity;
        float new_cost_each = new_cost / new_quantity;
        // 游标移动到行的开头
        fseek(fip, offset, SEEK_SET);
        fprintf(fip, "%10d:%-20.20s:%6d:%7.2f:%9c\n",
                part_num,
                part->description,
                new_quantity,
                new_cost_each,
                EMPTY_TAG);
        free(part);
    }
    
    rewind(fip);
    printf("operation is ok!\n");
}

/**
 卖掉零件， 需要计算利润并打印

 @param fip 存货记录文件指针
 
 */
void sell(FILE *fip) {
    int part_num;
    printf("part number: ");
    scanf("%d", &part_num);
    
    if (!check_input_part_num(part_num)) {
        return;
    }
    int quantity;
    printf("quantity: ");
    scanf("%d", &quantity);
    if (!check_input_quantity(quantity)) {
        return;
    }
    float price_each;
    printf("price_each: ");
    scanf("%f", &price_each);
    if (!check_input_cost_each(price_each)) {
        return;
    }
    
    long offset = part_num * LINE_BUF_SIZE;
    fseek(fip, offset, SEEK_SET);
    char *buffer = get_buffer_line();
    fgets(buffer, LINE_BUF_SIZE, fip);
    if (strlen(buffer) > 0) {
        Part *part = (Part *)malloc(sizeof(Part));
        resolve_part(buffer, part);
        
        // 当前的零件是否购卖
        if (part->quantity < quantity) {
            printf("Notice! Not enough parts to sell\n");
        } else {
            // 计算新的总价值
            double new_cost = part->cost_each * part->quantity - quantity * price_each;
            // 计算新的零件数量
            int new_quantity = part->quantity - quantity;
            // 计算新的单价
            float new_cost_each = new_cost / new_quantity;
            // 计算利润，新的单价*卖出去的数目 - 老的单价*卖出去的数目
            double profit = new_cost_each * quantity - part->cost_each * quantity;
            printf("sell ok, got profit %.2lf\n", profit);
            // 游标移动到行的开头
            fseek(fip, offset, SEEK_SET);
            fprintf(fip, "%10d:%-20.20s:%6d:%7.2f:%9c\n",
                    part_num,
                    part->description,
                    new_quantity,
                    new_cost_each,
                    EMPTY_TAG);
        }
        
        free(part);
    }
    
    rewind(fip);
    printf("operation is ok!\n");
}

/**
 删除一定数量的零件

 @param fip 存货记录文件指针
 */
void delete(FILE *fip) {
    int part_num;
    printf("part number: ");
    scanf("%d", &part_num);
    
    if (check_input_part_num(part_num)) {
        long offset = part_num * LINE_BUF_SIZE;
        fseek(fip, offset, SEEK_SET);
        // 清除description部分的数据
        fprintf(fip, "%10d:%-20.20s", part_num, " ");
        rewind(fip);
        printf("operation is ok!\n");
    }
}

/**
 打印指定零件的信息

 @param fip 存货记录文件指针
 */
void print(FILE *fip) {
    int part_num;
    printf("part number: ");
    scanf("%d", &part_num);
    
    if (check_input_part_num(part_num)) {
        long offset = part_num * LINE_BUF_SIZE;
        fseek(fip, offset, SEEK_SET);
        char *buffer = get_buffer_line();
        fgets(buffer, LINE_BUF_SIZE, fip);
        if (strlen(buffer) > 0) {
            Part *part = (Part *)malloc(sizeof(Part));
            resolve_part(buffer, part);
            printf("part number:%d\ndescription:%s\nquantity: %d\neach-cost: %f\n",
                    part->part_num,
                    part->description,
                    part->quantity,
                    part->cost_each);
            free(part);
            part = NULL;
        } else {
            printf("Notice! Not found the part which part number is %d\n", part_num);
        }
    }
    rewind(fip);
}

/**
 打印所有零件的信息

 @param fip 存货记录文件指针
 */
void print_all(FILE *fip) {
    char *buffer = get_buffer_line();
    // 跳到第2行, fseek会清除行末指示字符
    fseek(fip, LINE_BUF_SIZE, SEEK_SET);
    int ch;
    int part_num = 2;
    char *ptr = buffer;
    long pos = 0, cur_pos;
    while( (cur_pos = ftell(fip)) > pos ) {
        pos = cur_pos;
        ch = fgetc(fip);
        if (ch == END_TOKEN) {
            *ptr = '\0';
            if (strlen(buffer) > 0) {
                Part *part = (Part *)malloc(sizeof(Part));
                resolve_part(buffer, part);
                printf("part number: %d\ndescription: %s\nquantity: %d\neach-cost: %.2f\n",
                       part->part_num,
                       part->description,
                       part->quantity,
                       part->cost_each);
                printf("%s%c", SEPERATOR, END_TOKEN);
                free(part);
                fseek(fip, LINE_BUF_SIZE * part_num, SEEK_SET);
            }
            ptr = buffer;
            
        } else {
            *ptr++ = ch;
        }
    }
    rewind(fip);
}

/**
 统计零件的总额

 @param fip 存货记录文件指针
 */
void total(FILE *fip) {
    char *buffer = get_buffer_line();
    // 跳到第2行, fseek会清除行末指示字符
    fseek(fip, LINE_BUF_SIZE, SEEK_SET);
    int ch;
    int part_num = 2;
    char *ptr = buffer;
    long pos = 0, cur_pos;
    double sum = 0;
    while( (cur_pos = ftell(fip)) > pos ) {
        pos = cur_pos;
        ch = fgetc(fip);
        if (ch == END_TOKEN) {
            *ptr = '\0';
            if (strlen(buffer) > 0) {
                Part *part = (Part *)malloc(sizeof(Part));
                resolve_part(buffer, part);
                sum += part->quantity * part->cost_each;
                free(part);
                fseek(fip, LINE_BUF_SIZE * part_num, SEEK_SET);
            }
            ptr = buffer;
            
        } else {
            *ptr++ = ch;
        }
    }
    printf("%.2lf\n", sum);
    rewind(fip);
}

/**
 终止并退出程序

 @param fip 文件指针
 */
void end(FILE *fip) {
    if (fip != NULL) {
        fclose(fip);
    }
    printf("bye!\n");
    exit(EXIT_SUCCESS);
}

/* 操作方法名 */
static const char *oper_names[] = {
    "new", "buy", "sell", "delete", "print", "print_all", "total", "end", "help"
};

/**
 操作方法
 */
static void (* operate[]) (FILE *) = {
    new, buy, sell, delete, print, print_all, total, end, help
};

/**
 操作存货记录
 1 0, 1, 2, ...
 2 new, buy, sell, ..., new >user input
 3 new ..., buy ...
 
 存货记录表每一行的大小分配
 首行/头部信息：
     字符数  字段名
     10     可分配的零件号
     49     预留
     1      \n
 数据部分：
     字符数  字段名
     10      行号/零件号
     1      :
     20     零件描述(description)
     1      :
     6      零件数目(quantity)
     1      :
     10      零件单价
     1      :
     9     预留
     1      \n
 
 @param cmd 用户输入的字符
 @param fip 文件指针
 */
void handle_cmd(const char *cmd, FILE *fip) {
    // 第一个字符如果是数字字符，则通过序号去索引方法
    char ch = *cmd;
    if ( ch >= '0' && ch <= '9' ) {
        operate[ch - '0'](fip);
    } else {
        int len = sizeof(oper_names) / sizeof(oper_names[0]);
        for (int i = 0; i < len; i++) {
            // 判断用户输入的字符串是否是方法名
            if ( strcmp(cmd, oper_names[i]) == 0 ) {
                operate[i](fip);
            }
        }
    }
    
}

static jmp_buf start;

/**
 跳出当前操作

 @param signo 信号值
 */
void abort_current_oper(int signo) {
    longjmp(start, signo);
}

/**
 管理零件存货记录 -- 入口
 */
void parts_mgr(int argc, const char * argv[]) {
//    atexit(test_atexit);
    // 获取存货记录文件名
    const char *record_file = NULL;
    if (argc > 1) {
        record_file = argv[1];
    }
    if (record_file == NULL) {
        record_file = REC_CSV;
    }
    FILE *fip;
    // r+: 既可以读又可以写
    fip = fopen(record_file, "r+");
    if (fip == NULL) {
        perror(record_file);
//        exit(EXIT_FAILURE);
        // file not found, reopen
        printf("creating empty recfile..\n");
        fip = fopen(REC_CSV, "w+");
        if (fip == NULL) {
            perror(REC_CSV);
            exit(EXIT_FAILURE);
        }
    }
    help();
    // 捕获^C
    signal(SIGINT, abort_current_oper);
    int error_code = setjmp(start);
    if (error_code == SIGINT) {
        printf("\nuser aborted!\n");
    }
    printf(">");
    char commands[BUFFER_SIZE];
    while (fgets(commands, BUFFER_SIZE, stdin)) {
//        printf("你输入的命令: %s", commands);
        // 去除末尾的换行符\n
        commands[strlen(commands) - 1] = 0;
        handle_cmd(commands, fip);
        printf(">");
        fflush(stdin);
    }
    
}

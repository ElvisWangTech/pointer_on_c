//
//  main.c
//  pointers_on_c
//
//  Created by 汪意伟 on 2018/10/28.
//  Copyright © 2018年 汪意伟. All rights reserved.
//

#include "ch16.h"

int main(int argc, const char * argv[]) {
    // ch01
//    print_helloworld();
//    print_with_lineno();
//    print_checksum();
//    print_longest_line("/Users/wangyiwei/Downloads/test.log");
    
    // ch02
    // check_valid_c("/Users/wangyiwei/Projs/pointers_on_c/pointers_on_c/ch01/ch01_1.c");
    
    // ch04
//    printf("%d的平方根是 %f\n", 3, getSquareRoot(3));
//    printPrime(1, 1000000);
//    checkTriangle(3, 4, 5);
//    char src[] = "Hello world!";
//    char dst[20];
//    copy_n(dst, src, 19);
    
//    printDupLine("/tmp/test.txt");
    
//    int len = substr(dst, src, 6, 11);
//    printf("dst len is %d\n", len);
//    printf("%s\n", dst);
    
//    char str[] = "this is a  test, you know  i am      a good man!!";
//    deblank(str);
    
    // ch05
//    int a = -1;
//    printf("%d", a>>1);
//    printToLower();
//    printWithEncodeAlpha();
//    int rv = reverse_bits(25);
//    printf("%u reverse bits is %u\n", 25, rv);
//    unsigned int a = 0;
//    printf("%d", a<<=1);
    
//    printf("%x\n",store_bit_field(0x0,0x1,4,4));
//    printf("%x\n",store_bit_field(0xffff,0x123,15,4));
//    printf("%x\n",store_bit_field(0xffff,0x123,13,9));
    
    // ch06
    
//    char *p = find_char("ABCDEF", "XYZ");
//    char *p1 = find_char("ABCDEF", "XRCQEF");
//    if (p != NULL) {
//        printf("%c\n", *p);
//    }
//
//    if (p1 != NULL) {
//        printf("%c\n", *p1);
//    }
//    char * str = "ABCDEFG";
//    char const *substr = "CDE";
//    printf("old: %s substring: %s\n", str, substr);
//    int result = del_substr(str, substr);
//    printf("result %d\n\n", result);
//
//    char * str1 = "ABCDEFG";
//    char const *substr1 = "FGH";
//    printf("old: %s substring: %s\n", str1, substr1);
//    int result1 = del_substr(str1, substr1);
//    printf("result %d\n\n", result1);
//
//    char * str2 = "ABCDEFG";
//    char const *substr2 = "";
//    printf("old: %s substring: %s\n", str2, substr2);
//    int result2 = del_substr(str2, substr2);
//    printf("result %d\n\n", result2);
    
//    reverse_string("abcdefg");
    
//    eratosthenes_v2(100);
    
    // ch07
//    printf("%d\n", hermite(40, 1));
//    printf("%d\n", hermite2(40, 1));
    
//    printf("%d\n", gcd(60, 15));
//    char * s = "1988888";
//    printf("%s\n%d\n", s, ascii_to_integer(s));
    
//    int max = max_list(12,23,44,0,-1,-33,3);
//    printf("max is %d\n", max);
    
    // ch08
//    test_palindrome("abcdefedcba");
//
//    test_palindrome_v2("abcdefedcba");
    
//    int array[4][2];
//    printf("%x %x %x %x\n", array, array + 2, &array[1][2], &array[2][0]);
    
//    def_char_value();
//    float tax = single_tax(23351);
//    printf("%.2f\n", tax);
    
//    int matrix[][10] = {
//        {1},
//        {0,1},
//        {0,0,1},
//        {0,0,0,1},
//        {0,0,0,0,1},
//        {0,0,0,0,0,1},
//        {0,0,0,0,0,0,1},
//        {0,0,0,0,0,0,0,1},
//        {0,0,0,0,0,0,0,0,1},
//        {0,0,0,0,0,0,0,0,0,1},
//    };
//    int *p = matrix;
//    printf("%d\n", identity_matrix(matrix));
//    printf("%d\n", identity_matrix_n(p, 10));
//    int x = 3, y = 2, z = 4;
//    int m1[][2]={
//        {2, -6},
//        {3, 5},
//        {1, -1}
//    };
//    int m2[][4]={
//        {4,-2,-4,-5},
//        {-7,-3,6,7}
//    };
//    int r[12];
//    print_matrix(m1, x, y);
//    print_matrix(m2, y, z);
//    matrix_multiply(m1, m2, r, x, y, z);
//    print_matrix(r, x, z);
    
//    test_eight_queens();
//    count_char_type();
//    int f = palindrome("Madam,I'm Adam");
//    int f = palindrome("abc");
//    printf("%d \n", f);
    
//    count_word("/Users/wangyiwei/Downloads/when_you_are_old.txt", "and");
    
//    encrypt_string("Attack At Dawn", "trailblazers");
//    decrypt_string("Tpptad Tp Itvh", "trailblazers");
    
//    char dest[100];
//    dollars(dest, "");
//    dollars(dest, "1");
//    dollars(dest, "12");
//    dollars(dest, "123");
//    dollars(dest, "1234");
//    dollars(dest, "12345");
//    dollars(dest, "123456");
//    dollars(dest, "1234567");
//    dollars(dest, "12345678");
//    dollars(dest, "123456789");
    
    // ch11
//    printf("\n %u\n", malloc_t(500, char));
//    int *p = mycalloc2(4, sizeof(int));
//    printf("%x\n", p);
//    int *arr = gen_ints();
//    char *str = read_str_dup();
//    printf("%s\n", str);
    
    // ch12
//    Node *head = gen_nodes_new();
//    Node *target = get_node(head, 10);
//    int size = get_sll_size(&head);
//    printf("find?%d value?%d linked list size?%d\n", (target != NULL), target->value, size);
    
    /*
     prev: -2147483648 this: 5 next: 10
     prev: 5 this: 10 next: 15
     insert ok?1
     prev: -2147483648 this: 5 next: 10
     prev: 5 this: 10 next: 12
     prev: 10 this: 12 next: 15
     Program ended with exit code: 0
     */
//    DNode *head = gen_dnodes_new();
//    print_dnodes(head);
//    // 插入值为12的节点到双链表
//    int error_code = dll_insert(head, 12);
//    printf("insert ok?%d\n", error_code);
//    print_dnodes(head);
    
//    Node *head = gen_nodes_new();
//    print_nodes_val(head);
//    Node *new_head = sll_reverse(head);
//    print_nodes_val(new_head);
    
//    Node *head = gen_nodes_new();
//    print_nodes_val(head);
//    int error_code = sll_remove(&head, get_node(head, 15));
//    printf("remove ok?%d\n", error_code);
//    print_nodes_val(head);
    
//    DNode *head = gen_dnodes_new();
//    print_dnodes(head);
//    int error_code = dll_remove(&head, get_dnode(head, 15));
//    printf("remove ok?%d\n", error_code);
//    print_dnodes(head);
    
    // ch13
    
//    test_const_str();
//
//    mystery(0);
//    mystery(6);
//    mystery(30);
//    mystery(100);
//
//    int_to_hex(15);
    
//    count_char_type_new();
//    Node *head = gen_nodes_new();
//    find_node_with_callback(head, print_node_val);
    
//    char test[] = {'a', 'b', 'w', 'g', 'e', '1', '\0'};
//    sort_array(test, 6, sizeof(char), compare_char);
//    printf("%s\n", test);
//
//    char test_string[3][20] = {
//        "i love you",
//        "amy is my friend",
//        "monky"
//    };
//    sort_array(test_string, 3, 20, strcmp);
//    for (int i = 0; i < 3; i++) {
//        printf("%s\n", test_string[i]);
//    }
    
//    char ** follow = do_args(argc, argv, "abcdef", handle_arg, handle_illegal_arg);
//    printf("follow arg: %s\n", *follow);
    
//    print_ledger(2);
//    test_print();
//    print_std_char();
//    print_std_line();
    
//    copy_file("/tmp/a.txt", "/tmp/b.txt");
//    fetch_integers("/tmp/a.txt", "/tmp/b.txt");
//    count_avg_age("/Users/wangyiwei/ages.txt");
//    print_dump("/Users/wangyiwei/cdecl");
//    printf("%02X\n", 0);
    
//    fgrep(argc, argv);
//    sum(argc, argv);
//    parts_mgr(argc, argv);
//    test_questions();
//    get_min_base();
//    for (int i = 0; i < 100; i++) {
//        printf("%d\n", get_rand_num(1, 6));
//    }
//
//    speek_time_baby();
//    get_weekday(10, 14, 118);
//    printf("%.1lf\n", wind_chill(-5, 10));
//    printf("%.2f\n", payment(100000, 0.08, 20));
//    test_rand_func();
    
//    count_avg_age_new("/Users/wangyiwei/tmp/ages.txt");
//    check_birth(23);
    
    char test[] = {'a', 'b', 'w', 'g', 'e', '1', '\0'};
    insert_sort(test, 6, sizeof(char), compare_char);
    printf("%s\n", test);
    return 0;
}

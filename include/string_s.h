#ifndef DSA_IN_C_STRING_S_H
#define DSA_IN_C_STRING_S_H

typedef int bool;
#define false 0
#define true 1

// 返回字符串长度
int strlen_S(char string[]);

// 将字符串的各位相加转成 int
int string_to_int(char string []);

// 将字符串 s2 赋值给字符串 s1
bool strcpy_S(char s1[], char s2[]);

// 比较两个字符串
bool strcmp_S(char s1[], char s2[]);

#endif //DSA_IN_C_STRING_S_H

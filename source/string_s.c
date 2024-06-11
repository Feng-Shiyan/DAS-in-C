#include "../include/string_s.h"

// 返回字符串长度
int strlen_S(char string[])
{
    int i = 0;
    for ( ; string[i] != '\0'; i++);
    return i;
}

// 将字符串的各位相加转成 int
int string_to_int(char string [])
{
    int length = 0, sum = 0;
    length = strlen_S(string);
    for (int i = 0; i < length; i++)
    {
        sum += (int)(string[i]);
    }
    return sum;
}

// 将字符串 s2 赋值给字符串 s1
bool strcpy_S(char s1[], char s2[])
{
    int length_s1 = sizeof (s1);
    int length_s2 = sizeof (s2);

    if (length_s2 != length_s1) return false;
    for (int i = 0; i <length_s1 ||  i < length_s2 ;)
    {
       if ( s1[i] == s2[i]){
           i++;
       } else
           return false;
    }
    return true;
}

// 比较两个字符串
bool strcmp_S(char s1[], char s2[])
{
    int length_s1 = sizeof (s1);
    int length_s2 = sizeof (s2);

    if (length_s2 != length_s1) return false;
    for (int i = 0; i < length_s1 || i <length_s2;)
    {
        if ( s1[i] == s2[i])
        {
            i++;
        }else{
            return false;
        }
        return true;
    }
}


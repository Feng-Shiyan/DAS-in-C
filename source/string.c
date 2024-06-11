#include "../include/string.h"

char* stringInit(SqString* s)
{
    s->data = (char*) malloc(sizeof (char)*(MAX_SIZE+1) + sizeof (int));
    memset(s->data, '\0', MAX_SIZE+1);
    s->length = MAX_SIZE;
}

void stringAssignment(char* s1, SqString* s)
{
    int s1_length = strlen(s1) + 1;
    if (s->length < s1_length)
    {
        free(s);
        s = (SqString*) malloc(sizeof (char)*s1_length + sizeof (int));
    }
    for (int t = 0; t < s1_length; t++)
    {
        s->data[t] = s1[t];
    }
    s->data[s1_length+1] = '\0';
    s->length = s1_length;
}

void stringDisplay(SqString* s)
{
    for (int t = 0; t < s->length; t++)
    {
        printf("%c\n", s->data[t]);
    }
}

int BF(SqString* pattern, SqString* target)
{
    int count, flag = 0;
    int i = 0, j = 0;
    while (i < target->length && j < pattern->length)
    {
        count++;
        if (target->data[i] == pattern->data[j])
        {
            i++;
            j++;
        }else
        {
            j -= i-1;
            i=0;
        }
        if (i == target->length-1 && j == pattern->length-1)
            flag = 1;
    }
    if (flag = 0)
    {
        printf("��????????????\n");
        return -1;
    }
    else if (flag == 1)
        return i-j;
}



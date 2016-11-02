//
//  main.c
//  Cstring
//
//  Created by YI on 16/11/1.
//  Copyright © 2016年 Sandro. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

char *revstr(char *str, size_t len)//单纯的反转字符串
{
    char *start = str;
    char *end = str + len - 1;
    char ch;
    if (str != NULL) {
        while (start < end) {
            ch = *start;
            *start ++ = *end;
            *end -- = ch;
        }
    }

    return str;
}

int lenthofstr(char *str){//计算字符串的长度
    int count = 0;
    //char *pos = str;
    while (*str++) {
        //printf("%c--~-- \n",*str++);
        count++;
    }
    
    return count;
}

void str_reverse(char *begin, char *end)//就地反转指定区间[begin, end]的字符串
{
    if(begin != NULL && end != NULL){
    
    
        while (begin < end) {
            char ch = *begin;
            *begin++ = *end;
            *end-- = ch;
        }
    }
}

void konggefanzhuan(char *str){//遇到空格反转
    char *b = str;
    char *p = str;
    while (*p != '\0' ) {

            if (*p == ' ' ) {
                str_reverse(b, p-1);
                b = p+1;
                
            }else if (*(p+1) == '\0') {
                str_reverse(b, p);
            }
        
        p++;
    }
}

char *yasuo(char *str){//aaabbcccc->3a2b4c

    char newStr[1024] = {};
    int j = 0;
    int count = 1;
    while (*str++) {
        if (*str == *(str-1)) {
            count++;
        } else {
            if (count == 1) {
                newStr[j] = *(str-1);
                j++;
            } else {
                char a[2];
                sprintf(a, "%d",count);
                newStr[j] = a[0];
                newStr[j+1] = *(str-1);
                j = j+2;
            }
            count = 1;
        }

    }
    //感觉写的没错，逻辑肯定对啊，但是必须printf一次才能正常输出，好气啊
    //printf("----%s",newStr);
    //newStr[j] = 'a';
    //printf("2----%s",newStr);

    str = newStr;
    return str;
}

int main() {
    // insert code here...
    //char str1[] = { "hello  india mifun          "};
    
    char str1[1024];
    while (gets(str1)){

        printf("=%s=\n",yasuo(str1));

    }
    
    
    return 0;
}


/*
 /Users/yi/Desktop/ls/testcode/test10/CString/Cstring/Cstring/main.c:36:33: Implicitly declaring library function 'strlen' with type 'unsigned long (const char *)'
 */

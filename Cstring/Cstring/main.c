//
//  main.c
//  Cstring
//
//  Created by YI on 16/11/1.
//  Copyright © 2016年 Sandro. All rights reserved.
//

#include <stdio.h>

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


int main(int argc, const char * argv[]) {
    // insert code here...
    char str1[] = { "hello  india mifun          "};

    konggefanzhuan(str1);
    printf("~%s~\n",str1);
    printf("-%s-\n",revstr(str1, lenthofstr(str1)));
    return 0;
}


/*
 /Users/yi/Desktop/ls/testcode/test10/CString/Cstring/Cstring/main.c:36:33: Implicitly declaring library function 'strlen' with type 'unsigned long (const char *)'
 */

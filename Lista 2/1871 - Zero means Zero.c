#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int getlen(char* str);
char pop(char* str, int index);
int clear_zeroes(char* buf);

int main(){
    size_t bufsize = 11;
    char bufsum[bufsize];
    uint32_t n1,n2,sum=-1;
    
    while (1){
        scanf("%u %u", &n1, &n2);
        
        sum = n1 + n2;
        if (sum == 0) break;
        
        sprintf(bufsum, "%u", sum);
        clear_zeroes(bufsum);
        
        printf("%s\n", bufsum);
    }
    
    return 0;
}

int getlen(char* str){
    int count = 0;
    while (str[count++] != '\0');
    
    return count;
}

char pop(char* str, int index){
    char ch = str[index];
    for (int count = index; str[count] != '\0'; count++)
        str[count] = str[count+1];
    
    return ch;
}

int clear_zeroes(char* buf){
    for (int count = 0; buf[count] != '\0'; count++)
        while (buf[count] == '0')
            pop(buf, count);
    
    return 0;
}
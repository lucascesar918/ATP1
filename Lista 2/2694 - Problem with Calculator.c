#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

int atoi_range(char* str, int start, size_t size);

int main(){
    uint16_t count=0, sum=0, test_cases;
    size_t bufsize = 15;
    char buf[bufsize], ch;
    
    while ((ch = getchar()) != '\n' && count<bufsize)
        buf[count++] = ch;
        
    test_cases = atoi(buf);
    
    for(int j=1; j<=test_cases; j++){
        sum = count = 0;
        while ((ch = getchar()) != '\n' && count<bufsize)
            buf[count++] = ch;
            
        sum += atoi_range(buf, 2, 2);
        sum += atoi_range(buf, 5, 3);
        sum += atoi_range(buf, 11, 2);
        
        printf("%d\n", sum);
    }
    
    return 0;
}

int atoi_range(char* str, int start, size_t size){
    char strnum[size+1];
    strnum[size] = '\0';
    
    memcpy(strnum, str+start, size);
    
    return atoi(strnum);
}
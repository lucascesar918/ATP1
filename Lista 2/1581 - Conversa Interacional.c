#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

void read(char* str, size_t size);
int read_int(char* str, size_t size);

int main(){
  size_t bufsize = 21;
  char buf[bufsize], auxbuf[bufsize];
  int npeople, use_english;
  
  // reading test cases number
  int test_cases = read_int(buf, bufsize);
  
  // starting test cases loop
  for (int test_count = 1; test_count<=test_cases; test_count++){
    // read number of people
    npeople = read_int(buf, bufsize);
    
    // reset necessary variables
    use_english = 0;
    memset(buf, '\0', bufsize);
    memset(auxbuf, '\0', bufsize);
    
    // read first person's language
    read(buf, bufsize);
    
    // loop for reading other languages
    for (int j=1; j<npeople; j++){
      read(auxbuf, bufsize);
      
      if (strcmp(buf, auxbuf)) use_english = 1;
    }
    printf("%s\n", use_english ? "ingles" : buf);
  }
    
  return 0;
}

void read(char* str, size_t size){
  char ch;
  int count=0;
  while ((ch = getchar()) != '\n' && count<size)
    str[count++] = ch;
}

int read_int(char* str, size_t size){
  char buffer[size];
  read(buffer, size);
  
  return atoi(buffer);
}
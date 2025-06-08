#include <stdio.h>
#include <stdlib.h>

int is_endchar(char ch);
int has_substring(char* str, char* pattern);

int main(){
  size_t bufsize = 256;
  char* buf = (char*) malloc(sizeof(char) * bufsize);
  char* pattern = (char*) malloc(sizeof(char) * bufsize);

  printf("Digite uma palavra: ");
  fgets(buf, bufsize, stdin);
  printf("Palavra de busca: ");
  fgets(pattern, bufsize, stdin);

  printf("Palavra de busca %sestá na string", has_substring(buf, pattern) ? "" : "não ");

  free(buf);
  free(pattern);

  return 0;
}

int is_endchar(char ch){
  return ch == '\0' || ch == '\n';
}

int has_substring(char* str, char* pattern){
  if (!str || !pattern) return 0;
  size_t j;
  for (size_t c=0; !is_endchar(str[c]); c++){
    j = 0;
    while (!is_endchar(pattern[j]) && str[c+j] == pattern[j]) j++;
    if (is_endchar(pattern[j])) return 1;
  }

  return 0;
}

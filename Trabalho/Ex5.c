#include <stdio.h>
#include <stdlib.h>

int is_endchar(char ch) { return ch == '\0' || ch == '\n'; }
int count_pattern(char* str, char* pattern);

int main(){
  size_t bufsize = 256;
  char* string = (char*) malloc(sizeof(char) * bufsize);
  char* pattern = (char*) malloc(sizeof(char) * bufsize);

  if (!string || !pattern) perror("Erro ao alocar memória dinâmica.");

  printf("Digite uma palavra: ");
  fgets(string, bufsize, stdin);
  printf("Palavra de busca: ");
  fgets(pattern, bufsize, stdin);

  printf("A palavra de busca ocorre %d vez(es)\n", count_pattern(string, pattern));
  count_pattern(string, pattern);

  free(string);
  free(pattern);

  return 0;
}

int count_pattern(char* str, char* pattern){
  int count = 0;
  size_t c=0,j;

  while(!is_endchar(str[c])){
    j = 0;

    while(!is_endchar(pattern[j]) && str[c+j] == pattern[j]){
      j++;
    }

    if (is_endchar(pattern[j])) count++;
    c++;
  }

  return count;
}

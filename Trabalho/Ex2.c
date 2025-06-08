#include <stdio.h>
#include <stdlib.h>

void count_duplicates(char* buf);

int main()
{
  size_t const bufsize = 256;
  char* buf = (char*)malloc(sizeof(char)*bufsize);

  if(!buf) perror("Falha ao alocar memória.");

  printf("Digite uma palavra: ");
  fgets(buf, bufsize, stdin);
  count_duplicates(buf);

  return 0;
}

void count_duplicates(char* buf){
  int seen[256] = {0};
  size_t c = 0, j=0;
  int count = 0;

  while(buf[c] != '\0' && buf[c] != '\n'){
    if(!seen[buf[c]]){
      seen[buf[c]] = 1;
      j = c+1;
      count = 1;
      while(buf[j] != '\0' && buf[j] != '\n')
        if(buf[j++] == buf[c]) count++;
      printf("%c : %d ocorrência(s)\n", buf[c], count);
    }
    c++;
  }
}

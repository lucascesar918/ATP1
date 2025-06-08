#include <stdio.h>
#include <stdlib.h>

void substring(char* src, char* dest, size_t start, size_t end);

int main(){
  size_t bufsize = 256;
  char* buf = (char*)malloc(sizeof(char) * bufsize);
  char* auxbuf = (char*)malloc(sizeof(char) * bufsize);

  if (!buf || !auxbuf) perror("Falha ao alocar memória.");

  fgets(buf, bufsize, stdin);
  substring(buf, auxbuf, 4, 9);
  printf("%s\n", auxbuf);

  free(buf);
  free(auxbuf);
  return 0;
}

void substring(char* src, char* dest, size_t start, size_t end){
  if (start > end) return;
  size_t c=0, i=start;

  while (i<=end)
    dest[c++] = src[i++];

  dest[c] = '\0';
}

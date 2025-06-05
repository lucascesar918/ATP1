#include <stdio.h>

char* caesar_encode(char* str, size_t size, int key);
char* caesar_decode(char* str, size_t size, int key);

const int key = 5;

int main()
{
    size_t bufsize = 200;
    char buf[bufsize];
    int key;
    char decision;

printf("Digite \"e\" para codificar e \"d\" para decodificar: ");
    decision = getchar();
    if (decision != 'e' && decision !=  'd') return 1;
    printf(decision == 'e' ? "Digite uma palavra: " : "Digite uma palavra codificada: ");
    scanf("%s", buf);
    printf("Valor k: ");
    scanf("%d", &key);
    
    if (key < 1 || key > 10) { printf("Chave inválida!\nA chave deve estar entre 1 e 10."); return 1; }
    
    if (decision == 'e') printf("Palavra codificada: %s\n", caesar_encode(buf, bufsize, key));
    else printf("Palavra decodificada: %s\n", caesar_decode(buf, bufsize, key));

    return 0;
}

char* caesar_encode(char* str, size_t size, int k){
    for(size_t c=0; c<size && str[c] != '\0'; c++)
        str[c] += k;
    
    return str;
}

char* caesar_decode(char* str, size_t size, int k){
    for(size_t c=0; c<size && str[c] != '\0'; c++){
        str[c] -= k;
    }
    
    return str;
}
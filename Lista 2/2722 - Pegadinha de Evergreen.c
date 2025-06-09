#include <stdio.h>
#include <string.h>

int is_endchar(char ch){ return ch == '\0' || ch == '\n'; }

char* unscramble_evergreen(char* l1, char* l2, size_t size, char* res) {
    size_t i = 0, j = 0;

    while (l1[i] != '\0' || l2[i] != '\0') {
        if (l1[i] != '\0') res[j++] = l1[i++];
        if (l1[i] != '\0') res[j++] = l1[i++];
        if (l2[i - 2] != '\0') res[j++] = l2[i - 2];
        if (l2[i - 1] != '\0') res[j++] = l2[i - 1];
    }

    res[j] = '\0';
    return res;
}

int main() {
    size_t bufsize = 100;
    size_t bigbufsize = bufsize * 2;
    char line1[bufsize];
    char line2[bufsize];
    char bigbuf[bigbufsize];
    int test_cases;

    scanf("%d\n", &test_cases);

    for (int i = 0; i < test_cases; i++) {
        fgets(line1, bufsize, stdin);
        fgets(line2, bufsize, stdin);

        // limpa o \n
        line1[strcspn(line1, "\n")] = '\0';
        line2[strcspn(line2, "\n")] = '\0';

        printf("%s\n", unscramble_evergreen(line1, line2, bufsize, bigbuf));
    }

    return 0;
}



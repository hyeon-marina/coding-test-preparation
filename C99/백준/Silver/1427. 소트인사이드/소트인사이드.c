#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp_desc(const void *a, const void *b) {
    char ca = *(char *)a;
    char cb = *(char *)b;
    return (cb - ca);
}

int main() {
    char s[20];
    if (scanf("%s", s) != 1) return 0;
    int len = strlen(s);
    qsort(s, len, sizeof(char), cmp_desc);
    printf("%s\n", s);
    return 0;
}
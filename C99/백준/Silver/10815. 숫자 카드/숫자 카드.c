#include <stdio.h>
#include <stdlib.h>

int cmpInt(const void *a, const void *b) {
    int x = *(const int*)a, y = *(const int*)b;
    return (x > y) - (x < y);
}

int main(void) {
    int n;
    scanf("%d", &n);
    int *cards = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) scanf("%d", &cards[i]);
    qsort(cards, n, sizeof(int), cmpInt);

    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);
        int *p = (int*)bsearch(&x, cards, n, sizeof(int), cmpInt);
        printf("%d%c", (p != NULL) ? 1 : 0, (i + 1 < m) ? ' ' : '\n');
    }

    free(cards);
    return 0;
}

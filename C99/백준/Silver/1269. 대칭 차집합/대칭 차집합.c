#include <stdio.h>
#include <stdlib.h>

static int cmp_int(const void *a, const void *b) {
    int x = *(const int*)a, y = *(const int*)b;
    return (x > y) - (x < y);
}

int main(void) {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    int *A = (int*)malloc(sizeof(int) * n);
    int *B = (int*)malloc(sizeof(int) * m);
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);
    for (int i = 0; i < m; i++) scanf("%d", &B[i]);

    qsort(A, n, sizeof(int), cmp_int);
    qsort(B, m, sizeof(int), cmp_int);

    int i = 0, j = 0, inter = 0;
    while (i < n && j < m) {
        if (A[i] == B[j]) { inter++; i++; j++; }
        else if (A[i] < B[j]) i++;
        else j++;
    }

    int ans = n + m - 2 * inter;
    printf("%d\n", ans);

    free(A);
    free(B);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int cmp_int(const void *a, const void *b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    return (x > y) - (x < y);
}

int gcd(int a, int b) {
    while (b != 0) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int *pos = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) scanf("%d", &pos[i]);

    qsort(pos, n, sizeof(int), cmp_int);

    int g = pos[1] - pos[0];
    for (int i = 2; i < n; i++) {
        int d = pos[i] - pos[i - 1];
        g = gcd(g, d);
    }

    long long ans = 0;
    for (int i = 1; i < n; i++) {
        int d = pos[i] - pos[i - 1];
        ans += (d / g) - 1;
    }

    printf("%lld\n", ans);

    free(pos);
    return 0;
}

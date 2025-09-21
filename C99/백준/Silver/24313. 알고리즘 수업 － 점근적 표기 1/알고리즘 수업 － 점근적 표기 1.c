#include <stdio.h>

int main() {
    int a1, a0, c, n0;
    if (scanf("%d %d", &a1, &a0) != 2) return 0;
    if (scanf("%d", &c) != 1) return 0;
    if (scanf("%d", &n0) != 1) return 0;

    if (a1 <= c && (long long)a1 * n0 + a0 <= (long long)c * n0) {
        printf("1\n");
    } else {
        printf("0\n");
    }
    return 0;
}
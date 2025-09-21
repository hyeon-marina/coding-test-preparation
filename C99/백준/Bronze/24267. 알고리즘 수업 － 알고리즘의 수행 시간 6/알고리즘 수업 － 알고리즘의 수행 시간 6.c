#include <stdio.h>

int main() {
    long long n;
    if (scanf("%lld", &n) != 1) return 0;
    long long count = n * (n - 1) * (n - 2) / 6;
    printf("%lld\n", count);
    printf("3\n");
    return 0;
}
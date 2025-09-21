#include <stdio.h>

int main() {
    long long n;
    if (scanf("%lld", &n) != 1) return 0;
    long long result = n * n * n;
    printf("%lld\n", result);
    printf("3\n");
    return 0;
}
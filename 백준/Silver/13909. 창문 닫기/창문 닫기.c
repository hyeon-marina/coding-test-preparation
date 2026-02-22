#include <stdio.h>
#include <math.h>

int main(void) {
    long long n;
    if (scanf("%lld", &n) != 1) return 0;

    long long ans = (long long)sqrt((double)n);
    while ((ans + 1) * (ans + 1) <= n) ans++;
    while (ans * ans > n) ans--;

    printf("%lld\n", ans);
    return 0;
}
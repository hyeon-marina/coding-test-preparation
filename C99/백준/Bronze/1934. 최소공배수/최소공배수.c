#include <stdio.h>

long long gcd_ll(long long a, long long b) {
    while (b != 0) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main(void) {
    int t;
    if (scanf("%d", &t) != 1) return 0;

    while (t--) {
        long long a, b;
        scanf("%lld %lld", &a, &b);

        long long g = gcd_ll(a, b);
        long long lcm = (a / g) * b;
        printf("%lld\n", lcm);
    }
    return 0;
}

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
    long long a, b, c, d;
    scanf("%lld %lld", &a, &b);
    scanf("%lld %lld", &c, &d);

    long long num = a * d + c * b;
    long long den = b * d;

    long long g = gcd_ll(num, den);
    printf("%lld %lld\n", num / g, den / g);
    return 0;
}

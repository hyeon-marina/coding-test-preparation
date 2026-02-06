#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

static uint64_t mul_mod(uint64_t a, uint64_t b, uint64_t mod) {
    __uint128_t r = (__uint128_t)a * b;
    return (uint64_t)(r % mod);
}

static uint64_t pow_mod(uint64_t a, uint64_t d, uint64_t mod) {
    uint64_t r = 1;
    while (d) {
        if (d & 1) r = mul_mod(r, a, mod);
        a = mul_mod(a, a, mod);
        d >>= 1;
    }
    return r;
}

static int is_prime(uint64_t n) {
    if (n < 2) return 0;
    uint64_t small[] = {2,3,5,7,11,13,17,19,23,29,31,37};
    for (int i = 0; i < 12; i++) {
        if (n == small[i]) return 1;
        if (n % small[i] == 0) return 0;
    }

    uint64_t d = n - 1;
    int s = 0;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }

    uint64_t bases[] = {2,3,5,7,11,13,17};
    for (int i = 0; i < 7; i++) {
        uint64_t a = bases[i] % n;
        if (a == 0) continue;

        uint64_t x = pow_mod(a, d, n);
        if (x == 1 || x == n - 1) continue;

        int comp = 1;
        for (int r = 1; r < s; r++) {
            x = mul_mod(x, x, n);
            if (x == n - 1) { comp = 0; break; }
        }
        if (comp) return 0;
    }
    return 1;
}

static uint64_t next_prime(uint64_t n) {
    if (n <= 2) return 2;
    if ((n & 1) == 0) n++;
    while (!is_prime(n)) n += 2;
    return n;
}

int main(void) {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        uint64_t n;
        scanf("%" SCNu64, &n);
        printf("%" PRIu64 "\n", next_prime(n));
    }
    return 0;
}

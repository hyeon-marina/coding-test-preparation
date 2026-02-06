#include <bits/stdc++.h>
using namespace std;

using u64 = unsigned long long;
using u128 = __uint128_t;

static u64 mul_mod(u64 a, u64 b, u64 mod) {
    return (u128)a * b % mod;
}

static u64 pow_mod(u64 a, u64 d, u64 mod) {
    u64 r = 1;
    while (d) {
        if (d & 1) r = mul_mod(r, a, mod);
        a = mul_mod(a, a, mod);
        d >>= 1;
    }
    return r;
}

static bool is_prime(u64 n) {
    if (n < 2) return false;
    static u64 small[] = {2,3,5,7,11,13,17,19,23,29,31,37};
    for (u64 p : small) {
        if (n == p) return true;
        if (n % p == 0) return false;
    }

    u64 d = n - 1;
    int s = 0;
    while ((d & 1) == 0) d >>= 1, s++;

    static u64 bases[] = {2,3,5,7,11,13,17};
    for (u64 a : bases) {
        a %= n;
        if (a == 0) continue;

        u64 x = pow_mod(a, d, n);
        if (x == 1 || x == n - 1) continue;

        bool composite = true;
        for (int r = 1; r < s; r++) {
            x = mul_mod(x, x, n);
            if (x == n - 1) { composite = false; break; }
        }
        if (composite) return false;
    }
    return true;
}

static u64 next_prime(u64 n) {
    if (n <= 2) return 2;
    if ((n & 1) == 0) n++;
    while (!is_prime(n)) n += 2;
    return n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        u64 n;
        cin >> n;
        cout << next_prime(n) << "\n";
    }
    return 0;
}

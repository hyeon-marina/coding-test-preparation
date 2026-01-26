#include <bits/stdc++.h>
using namespace std;

static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15ULL;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
    x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
    return x ^ (x >> 31);
}

struct U64Hash {
    size_t operator()(uint64_t x) const noexcept {
        return (size_t)splitmix64(x);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = (int)s.size();

    const uint32_t MOD1 = 1'000'000'007u;
    const uint32_t MOD2 = 1'000'000'009u;
    const uint32_t BASE = 911'382'323u;

    vector<uint32_t> pow1(n + 1), pow2(n + 1), pref1(n + 1), pref2(n + 1);
    pow1[0] = 1; pow2[0] = 1;

    for (int i = 0; i < n; i++) {
        uint32_t x = (unsigned char)s[i];
        pow1[i + 1] = (uint64_t)pow1[i] * BASE % MOD1;
        pow2[i + 1] = (uint64_t)pow2[i] * BASE % MOD2;
        pref1[i + 1] = ((uint64_t)pref1[i] * BASE + x) % MOD1;
        pref2[i + 1] = ((uint64_t)pref2[i] * BASE + x) % MOD2;
    }

    unordered_set<uint64_t, U64Hash> seen;
    seen.reserve((size_t)n * (n + 1) / 2);

    for (int l = 0; l < n; l++) {
        for (int r = l + 1; r <= n; r++) {
            int len = r - l;
            uint32_t h1 = (pref1[r] + MOD1 - (uint64_t)pref1[l] * pow1[len] % MOD1) % MOD1;
            uint32_t h2 = (pref2[r] + MOD2 - (uint64_t)pref2[l] * pow2[len] % MOD2) % MOD2;

            uint64_t key = ((uint64_t)len << 40) ^ ((uint64_t)h1 << 20) ^ (uint64_t)h2;
            seen.insert(key);
        }
    }

    cout << seen.size() << "\n";
    return 0;
}

import sys

def main():
    s = sys.stdin.readline().strip()
    n = len(s)

    MOD1 = 1_000_000_007
    MOD2 = 1_000_000_009
    BASE = 911382323

    pow1 = [1] * (n + 1)
    pow2 = [1] * (n + 1)
    pref1 = [0] * (n + 1)
    pref2 = [0] * (n + 1)

    for i, ch in enumerate(s):
        x = ord(ch)
        pow1[i + 1] = (pow1[i] * BASE) % MOD1
        pow2[i + 1] = (pow2[i] * BASE) % MOD2
        pref1[i + 1] = (pref1[i] * BASE + x) % MOD1
        pref2[i + 1] = (pref2[i] * BASE + x) % MOD2

    def get_hash(l, r):
        h1 = (pref1[r] - pref1[l] * pow1[r - l]) % MOD1
        h2 = (pref2[r] - pref2[l] * pow2[r - l]) % MOD2
        return h1, h2

    seen = set()
    for l in range(n):
        for r in range(l + 1, n + 1):
            h1, h2 = get_hash(l, r)
            key = (r - l) << 64 | (h1 << 32) | h2
            seen.add(key)

    print(len(seen))

if __name__ == "__main__":
    main()

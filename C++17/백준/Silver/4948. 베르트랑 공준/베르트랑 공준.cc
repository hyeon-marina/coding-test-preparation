#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> qs;
    int n, maxN = 0;
    while (cin >> n) {
        if (n == 0) break;
        qs.push_back(n);
        maxN = max(maxN, n);
    }
    if (qs.empty()) return 0;

    int limit = 2 * maxN;
    vector<bool> isPrime(limit + 1, true);
    if (limit >= 0) isPrime[0] = false;
    if (limit >= 1) isPrime[1] = false;

    for (int p = 2; p * p <= limit; p++) {
        if (isPrime[p]) {
            for (int x = p * p; x <= limit; x += p) {
                isPrime[x] = false;
            }
        }
    }

    vector<int> prefix(limit + 1, 0);
    int cnt = 0;
    for (int i = 0; i <= limit; i++) {
        if (isPrime[i]) cnt++;
        prefix[i] = cnt;
    }

    for (int q : qs) {
        cout << (prefix[2 * q] - prefix[q]) << '\n';
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<int> nums(t);
    int max_n = 0;
    for (int i = 0; i < t; i++) {
        cin >> nums[i];
        max_n = max(max_n, nums[i]);
    }

    vector<char> is_prime(max_n + 1, 1);
    if (max_n >= 0) is_prime[0] = 0;
    if (max_n >= 1) is_prime[1] = 0;

    for (int i = 2; 1LL * i * i <= max_n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= max_n; j += i) {
                is_prime[j] = 0;
            }
        }
    }

    for (int n : nums) {
        int half = n / 2;
        int cnt = 0;
        for (int p = 2; p <= half; p++) {
            if (is_prime[p] && is_prime[n - p]) cnt++;
        }
        cout << cnt << "\n";
    }
    return 0;
}

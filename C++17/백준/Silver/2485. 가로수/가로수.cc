#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> pos(n);
    for (int i = 0; i < n; i++) cin >> pos[i];
    sort(pos.begin(), pos.end());

    vector<int> diffs;
    diffs.reserve(n - 1);
    for (int i = 1; i < n; i++) diffs.push_back(pos[i] - pos[i - 1]);

    int g = diffs[0];
    for (int i = 1; i < (int)diffs.size(); i++) g = std::gcd(g, diffs[i]);

    long long ans = 0;
    for (int d : diffs) ans += (d / g) - 1;

    cout << ans << "\n";
    return 0;
}

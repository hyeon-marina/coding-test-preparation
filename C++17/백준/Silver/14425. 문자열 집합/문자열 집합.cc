#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    unordered_set<string> s;
    s.reserve(n * 2);
    s.max_load_factor(0.7f);

    string x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        s.insert(x);
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        cin >> x;
        if (s.find(x) != s.end()) ans++;
    }

    cout << ans << "\n";
    return 0;
}

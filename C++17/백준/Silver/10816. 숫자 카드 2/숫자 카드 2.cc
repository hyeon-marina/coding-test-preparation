#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int q;
        cin >> q;
        auto range = equal_range(a.begin(), a.end(), q);
        int ans = (int)(range.second - range.first);
        if (i) cout << ' ';
        cout << ans;
    }
    cout << '\n';
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    unordered_set<string> heard;
    heard.reserve(n * 2);

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        heard.insert(s);
    }

    vector<string> ans;
    ans.reserve(min(n, m));

    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if (heard.find(s) != heard.end()) ans.push_back(s);
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (auto &s : ans) cout << s << "\n";
    return 0;
}

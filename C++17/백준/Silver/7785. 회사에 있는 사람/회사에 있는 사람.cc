#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    unordered_set<string> present;
    present.reserve(n * 2);

    for (int i = 0; i < n; i++) {
        string name, action;
        cin >> name >> action;
        if (action == "enter") present.insert(name);
        else present.erase(name);
    }

    vector<string> v(present.begin(), present.end());
    sort(v.begin(), v.end(), greater<string>());

    for (auto &s : v) cout << s << "\n";
    return 0;
}

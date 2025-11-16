#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int,int>> arr;
    arr.reserve(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        arr.emplace_back(x, y);
    }
    sort(arr.begin(), arr.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
        if (a.second != b.second) return a.second < b.second;
        return a.first < b.first;
    });
    for (auto &p : arr) {
        cout << p.first << ' ' << p.second << '\n';
    }
    return 0;
}
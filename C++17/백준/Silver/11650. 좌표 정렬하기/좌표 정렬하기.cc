#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end()); // pair 기본 비교: first 오름차순, 같으면 second 오름차순
    for (auto &p : v) {
        cout << p.first << " " << p.second << "\n";
    }
    return 0;
}
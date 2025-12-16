#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> cards(n);
    for (int i = 0; i < n; i++) cin >> cards[i];
    sort(cards.begin(), cards.end());

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        cout << (binary_search(cards.begin(), cards.end(), x) ? 1 : 0);
        if (i + 1 < m) cout << ' ';
    }
    return 0;
}

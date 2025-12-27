#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> numToName(n + 1);
    unordered_map<string, int> nameToNum;
    nameToNum.reserve(n * 2);

    for (int i = 1; i <= n; i++) {
        cin >> numToName[i];
        nameToNum[numToName[i]] = i;
    }

    for (int i = 0; i < m; i++) {
        string q;
        cin >> q;
        if (!q.empty() && isdigit((unsigned char)q[0])) {
            cout << numToName[stoi(q)] << "\n";
        } else {
            cout << nameToNum[q] << "\n";
        }
    }
    return 0;
}

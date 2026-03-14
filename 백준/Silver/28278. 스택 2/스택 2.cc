#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> st;
    st.reserve(n);

    while (n--) {
        int op;
        cin >> op;

        if (op == 1) {
            int x;
            cin >> x;
            st.push_back(x);
        } else if (op == 2) {
            if (st.empty()) cout << -1 << '\n';
            else {
                cout << st.back() << '\n';
                st.pop_back();
            }
        } else if (op == 3) {
            cout << st.size() << '\n';
        } else if (op == 4) {
            cout << (st.empty() ? 1 : 0) << '\n';
        } else if (op == 5) {
            if (st.empty()) cout << -1 << '\n';
            else cout << st.back() << '\n';
        }
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

long long gcd_ll(long long a, long long b) {
    while (b != 0) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;

        long long g = gcd_ll(a, b);
        long long lcm = (a / g) * b;
        cout << lcm << '\n';
    }
    return 0;
}

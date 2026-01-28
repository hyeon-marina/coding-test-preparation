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

    long long a, b, c, d;
    cin >> a >> b;
    cin >> c >> d;

    long long num = a * d + c * b;
    long long den = b * d;

    long long g = gcd_ll(num, den);
    cout << num / g << ' ' << den / g << '\n';
    return 0;
}

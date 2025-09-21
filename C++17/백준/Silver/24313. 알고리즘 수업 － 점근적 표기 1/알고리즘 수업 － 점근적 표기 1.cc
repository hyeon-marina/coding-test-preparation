#include <iostream>
using namespace std;

int main() {
    int a1, a0, c, n0;
    cin >> a1 >> a0;
    cin >> c;
    cin >> n0;

    long long lhs = (long long)a1 * n0 + a0;
    long long rhs = (long long)c * n0;

    if (a1 <= c && lhs <= rhs) {
        cout << 1;
    } else {
        cout << 0;
    }
    return 0;
}
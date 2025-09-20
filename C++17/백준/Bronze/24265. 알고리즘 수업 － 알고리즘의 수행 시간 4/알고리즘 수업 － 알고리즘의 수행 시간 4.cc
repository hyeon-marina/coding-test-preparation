#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    if (!(cin >> n)) return 0;
    long long count = n * (n - 1) / 2;
    cout << count << "\n";
    cout << 2 << "\n";
    return 0;
}
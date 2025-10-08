#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int count5 = n / 5;
    while (count5 >= 0) {
        int rem = n - count5 * 5;
        if (rem % 3 == 0) {
            int count3 = rem / 3;
            cout << (count5 + count3) << "\n";
            return 0;
        }
        count5--;
    }
    cout << -1 << "\n";
    return 0;
}
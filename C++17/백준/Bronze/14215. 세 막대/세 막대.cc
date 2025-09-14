#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;
    int s[3] = {a, b, c};
    sort(s, s + 3);
    int x = s[0], y = s[1], z = s[2];

    int result;
    if (x + y > z) {
        result = x + y + z;
    } else {
        result = 2 * (x + y) - 1;
    }

    cout << result << "\n";
    return 0;
}
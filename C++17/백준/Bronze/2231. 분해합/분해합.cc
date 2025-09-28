#include <iostream>
using namespace std;

int self_sum(int x) {
    int s = x;
    while (x > 0) {
        s += x % 10;
        x /= 10;
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int ans = 0;

    int d = to_string(N).size();
    int start = N - 9 * d;
    if (start < 1) start = 1;

    for (int m = start; m < N; m++) {
        if (self_sum(m) == N) {
            ans = m;
            break;
        }
    }

    cout << ans << "\n";
    return 0;
}
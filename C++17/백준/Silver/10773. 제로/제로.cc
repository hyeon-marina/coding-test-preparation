#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int K;
    cin >> K;

    vector<int> v;
    for (int i = 0; i < K; i++) {
        int num;
        cin >> num;
        if (num == 0) {
            v.pop_back();
        } else {
            v.push_back(num);
        }
    }

    long long sum = 0;
    for (int n : v) {
        sum += n;
    }

    cout << sum << "\n";
    return 0;
}
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int count = 0;
    int num = 666;
    while (true) {
        string s = to_string(num);
        if (s.find("666") != string::npos) {
            count++;
            if (count == N) {
                cout << num << "\n";
                break;
            }
        }
        num++;
    }
    return 0;
}